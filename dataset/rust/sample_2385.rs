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
        self.sequence.push((self.current_value * 10_f64.powi(self.precision as i32)).round() / 10_f64.powi(self.precision as i32));
    }

    fn get_sequence(&self) -> &Vec<f64> {
        &self.sequence
    }
}

struct PrecisionManager {
    max_precision: usize,
    current_precision: usize,
}

impl PrecisionManager {
    fn new(max_precision: usize) -> Self {
        PrecisionManager {
            max_precision,
            current_precision: 0,
        }
    }

    fn increment_precision(&mut self) {
        if self.current_precision < self.max_precision {
            self.current_precision += 1;
        }
    }

    fn get_precision(&self) -> usize {
        self.current_precision
    }
}

struct Controller {
    sequence_tracker: SequenceTracker,
    precision_manager: PrecisionManager,
}

impl Controller {
    fn new(sequence_tracker: SequenceTracker, precision_manager: PrecisionManager) -> Self {
        Controller {
            sequence_tracker,
            precision_manager,
        }
    }

    fn run(&mut self) {
        let increment = 0.1;
        loop {
            self.sequence_tracker.update_value(increment);
            self.precision_manager.increment_precision();
            let precision = self.precision_manager.get_precision();
            self.sequence_tracker.precision = precision;
            println!("{:?}", self.sequence_tracker.get_sequence());
        }
    }
}

fn main() {
    let precision_manager = PrecisionManager::new(5);
    let sequence_tracker = SequenceTracker::new(0);
    let mut controller = Controller::new(sequence_tracker, precision_manager);
    controller.run();
}