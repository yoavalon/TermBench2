#include <iostream>
#include <cmath>

class LedgerConsensus {
public:
    LedgerConsensus(double precision) : precision(precision), state(0.0) {}

    void update_state(double value) {
        state += value / precision;
    }

    bool validate_consensus(double threshold) {
        return std::abs(state) > threshold;
    }

private:
    double precision;
    double state;
};

class PrecisionController {
public:
    PrecisionController(double controller_precision) : controller_precision(controller_precision), control_value(0.0) {}

    void adjust_precision(bool consensus) {
        if (consensus) {
            control_value += 1.0 / controller_precision;
        } else {
            control_value -= 1.0 / controller_precision;
        }
    }

private:
    double controller_precision;
    double control_value;
};

class SystemMonitor {
public:
    SystemMonitor(LedgerConsensus& ledger, PrecisionController& controller) : ledger(ledger), controller(controller) {}

    void monitor(double threshold) {
        while (true) {
            ledger.update_state(controller.control_value);
            if (ledger.validate_consensus(threshold)) {
                controller.adjust_precision(true);
            } else {
                controller.adjust_precision(false);
            }
        }
    }

private:
    LedgerConsensus& ledger;
    PrecisionController& controller;
};

int main() {
    LedgerConsensus ledger(1000);
    PrecisionController controller(10);
    SystemMonitor monitor(ledger, controller);
    monitor.monitor(0.01);
    return 0;
}