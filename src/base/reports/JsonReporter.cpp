// Copyright (c) Signal Estimator authors
// Licensed under MIT

#include "reports/JsonReporter.hpp"
#include "core/Time.hpp"

#include <cstdio>

namespace signal_estimator {

JsonReporter::JsonReporter(const Config&, const DevInfo& dev_info, JsonPrinter& printer)
    : printer_(printer)
    , dev_name_(dev_info.short_name) {
}

void JsonReporter::report_latency(double sw_hw, double hw, double hw_avg, int) {
    printer_.write_line("{\"type\": \"latency\", \"device\": \"%s\", \"timestamp\": %llu,"
                        " \"sw_hw\": %f, \"hw\": %f, \"hw_avg\": %f}",
        dev_name_.c_str(), (unsigned long long)wallclock_timestamp_ns(), sw_hw, hw,
        hw_avg);
}

void JsonReporter::report_losses(
    double loss_rate, double avg_loss_rate, double loss_ratio, int) {
    printer_.write_line("{\"type\": \"losses\", \"device\": \"%s\", \"timestamp\": %llu,"
                        " \"rate\": %f, \"rate_avg\": %f, \"ratio\": %f}",
        dev_name_.c_str(), (unsigned long long)wallclock_timestamp_ns(), loss_rate,
        avg_loss_rate, loss_ratio);
}

void JsonReporter::report_jitter(double swdev_avg, double swdev_per, double hwdev_avg,
    double hwdev_per, double hwbuf_avg, double hwbuf_per, int) {
    printer_.write_line(
        "{\"type\": \"io_jitter\", \"device\": \"%s\", \"timestamp\": %llu,"
        " \"swdev_avg\": %f, \"swdev_per\": %f,"
        " \"hwdev_avg\": %f, \"hwdev_per\": %f,"
        " \"hwbuf_avg\": %f, \"hwbuf_per\": %f}",
        dev_name_.c_str(), (unsigned long long)wallclock_timestamp_ns(), swdev_avg,
        swdev_per, hwdev_avg, hwdev_per, hwbuf_avg, hwbuf_per);
}

} // namespace signal_estimator
