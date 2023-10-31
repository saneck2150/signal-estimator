// Copyright (c) Signal Estimator authors
// Licensed under MIT

#include "reports/TextReporter.hpp"

#include <cstdio>

namespace signal_estimator {

TextReporter::TextReporter(const Config& config, const DevInfo& dev_info) {
    if (config.show_device_names && !dev_info.short_name.empty()) {
        suffix_ = "[" + dev_info.short_name + "]";
    }
    sign_ = config.diff_inputs;
}

void TextReporter::report_latency(
    double sw_hw, double hw, double hw_avg, int sma_window) {
    if (sign_) {
        printf("latency%s:"
               "  sw+hw %+7.3fms  hw %+7.3fms  hw_avg%d %+7.3fms\n",
            suffix_.c_str(), sw_hw, hw, sma_window, hw_avg);
    } else {
        printf("latency%s:"
               "  sw+hw %7.3fms  hw %7.3fms  hw_avg%d %7.3fms\n",
            suffix_.c_str(), sw_hw, hw, sma_window, hw_avg);
    }
}

void TextReporter::report_losses(
    double loss_rate, double avg_loss_rate, double loss_ratio, int sma_window) {
    if (sign_) {
        printf("losses%s:"
               "  rate %+5.1f/sec  rate_avg%d %+5.1f/sec  ratio %+6.2f%%\n",
            suffix_.c_str(), loss_rate, sma_window, avg_loss_rate, loss_ratio);
    } else {
        printf("losses%s:"
               "  rate %5.1f/sec  rate_avg%d %5.1f/sec  ratio %6.2f%%\n",
            suffix_.c_str(), loss_rate, sma_window, avg_loss_rate, loss_ratio);
    }
}

void TextReporter::report_jitter(double swdev_avg, double swdev_per, double hwdev_avg,
    double hwdev_per, double hwbuf_avg, double hwbuf_per, int percentile) {
    printf("io_jitter%s:"
           "  sw avg %6.3fms p%d %6.3fms"
           "  hw avg %6.3fms p%d %6.3fms"
           "  buf avg %6.3fms p%d %6.3fms\n",
        suffix_.c_str(), swdev_avg, percentile, swdev_per, hwdev_avg, percentile,
        hwdev_per, hwbuf_avg, percentile, hwbuf_per);
}

} // namespace signal_estimator
