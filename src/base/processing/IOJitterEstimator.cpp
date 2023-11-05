// Copyright (c) Signal Estimator authors
// Licensed under MIT

#include "processing/IOJitterEstimator.hpp"
#include "core/Time.hpp"
#include "reports/IReporter.hpp"

namespace signal_estimator {

IOJitterEstimator::JitterStats::JitterStats(const Config& config, const DevInfo& dev_info)
    : dev_avg(config.io_jitter_window)
    , dev_per(config.io_jitter_window, config.io_jitter_percentile / 100.)
    , ideal_period((double)config.samples_to_ns(dev_info.period_size) / Millisecond) {
}

void IOJitterEstimator::JitterStats::update(nanoseconds_t next_ts) {
    if (prev_ts) {
        // delta between two frames
        const double delta = double(next_ts - prev_ts) / Millisecond;
        // deviation of delta from ideal period
        const double deviation = std::abs(delta - ideal_period);
        // statistics
        dev_avg.add(deviation);
        dev_per.add(deviation);
    }
    prev_ts = next_ts;
}

IOJitterEstimator::IOJitterEstimator(
    const Config& config, const DevInfo& dev_info, IReporter& reporter)
    : config_(config)
    , dev_info_(dev_info)
    , thread_(&IOJitterEstimator::run_, this)
    , sw_stats_(config, dev_info)
    , hw_stats_(config, dev_info)
    , reporter_(reporter) {
}

IOJitterEstimator::~IOJitterEstimator() {
    queue_.push(nullptr);

    if (thread_.joinable()) {
        thread_.join();
    }
}

void IOJitterEstimator::add_output(FramePtr frame) {
    if (dev_info_.dir == Dir::Output) {
        queue_.push(std::move(frame));
    }
}

void IOJitterEstimator::add_input(FramePtr frame) {
    if (dev_info_.dir == Dir::Input) {
        queue_.push(std::move(frame));
    }
}

void IOJitterEstimator::run_() {
    while (auto frame = queue_.wait_pop()) {
        sw_stats_.update(frame->sw_frame_time());
        hw_stats_.update(frame->hw_frame_time());

        if (sw_stats_.dev_avg.is_full() && report_limiter_.allow() > 0) {
            IOJitterReport rep;

            rep.swdev_avg = sw_stats_.dev_avg.get();
            rep.swdev_per = sw_stats_.dev_per.get();
            rep.hwdev_avg = hw_stats_.dev_avg.get();
            rep.hwdev_per = hw_stats_.dev_per.get();

            reporter_.report(rep);
        }
    }
}

} // namespace signal_estimator
