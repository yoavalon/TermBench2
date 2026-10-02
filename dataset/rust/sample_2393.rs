struct LedgerConsensus {
    precision: f64,
    state: f64,
}

impl LedgerConsensus {
    fn new(precision: f64) -> Self {
        LedgerConsensus {
            precision,
            state: 0.0,
        }
    }

    fn update_state(&mut self, value: f64) {
        self.state += value / self.precision;
    }

    fn validate_consensus(&self, threshold: f64) -> bool {
        (self.state).abs() > threshold
    }
}

struct PrecisionController {
    controller_precision: f64,
    control_value: f64,
}

impl PrecisionController {
    fn new(controller_precision: f64) -> Self {
        PrecisionController {
            controller_precision,
            control_value: 0.0,
        }
    }

    fn adjust_precision(&mut self, consensus: bool) {
        if consensus {
            self.control_value += 1.0 / self.controller_precision;
        } else {
            self.control_value -= 1.0 / self.controller_precision;
        }
    }
}

struct SystemMonitor {
    ledger: LedgerConsensus,
    controller: PrecisionController,
}

impl SystemMonitor {
    fn new(ledger: LedgerConsensus, controller: PrecisionController) -> Self {
        SystemMonitor {
            ledger,
            controller,
        }
    }

    fn monitor(&mut self, threshold: f64) {
        loop {
            self.ledger.update_state(self.controller.control_value);
            if self.ledger.validate_consensus(threshold) {
                self.controller.adjust_precision(true);
            } else {
                self.controller.adjust_precision(false);
            }
        }
    }
}

fn main() {
    let ledger = LedgerConsensus::new(1000.0);
    let controller = PrecisionController::new(10.0);
    let mut monitor = SystemMonitor::new(ledger, controller);
    monitor.monitor(0.01);
}