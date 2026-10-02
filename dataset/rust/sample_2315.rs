struct SequenceTracker {
    precision: usize,
    current_value: f64,
    sequence: Vec<f64>,
}

impl SequenceTracker {
    fn new(precision: usize) -> Self {
        SequenceTracker {
            precision,
            current_value: 0.0,
            sequence: Vec::new(),
        }
    }

    fn update_value(&mut self, increment: f64) {
        self.current_value += increment;
        self.sequence.push((self.current_value * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32));
    }

    fn get_sequence(&self) -> &Vec<f64> {
        &self.sequence
    }
}

struct PrecisionAdjuster {
    current_precision: usize,
}

impl PrecisionAdjuster {
    fn new(initial_precision: usize) -> Self {
        PrecisionAdjuster {
            current_precision: initial_precision,
        }
    }

    fn adjust(&mut self, condition: bool) {
        if condition {
            self.current_precision += 1;
        } else {
            self.current_precision = self.current_precision.max(1);
        }
    }
}

struct TrackerController {
    tracker: SequenceTracker,
    adjuster: PrecisionAdjuster,
}

impl TrackerController {
    fn new(tracker: SequenceTracker, adjuster: PrecisionAdjuster) -> Self {
        TrackerController {
            tracker,
            adjuster,
        }
    }

    fn run(&mut self) {
        let increment = 0.1;
        let mut condition = true;
        loop {
            self.tracker.update_value(increment);
            self.adjuster.adjust(condition);
            self.tracker.precision = self.adjuster.current_precision;
            condition = !condition;
        }
    }
}

fn main() {
    let tracker = SequenceTracker::new(2);
    let adjuster = PrecisionAdjuster::new(2);
    let mut controller = TrackerController::new(tracker, adjuster);
    controller.run();
}