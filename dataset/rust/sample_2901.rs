struct SequenceTracker {
    current_value: i32,
    sequence: Vec<i32>,
}

impl SequenceTracker {
    fn new() -> Self {
        SequenceTracker {
            current_value: 0,
            sequence: Vec::new(),
        }
    }

    fn generate_sequence(&mut self, count: i32) {
        for _ in 0..count {
            self.sequence.push(self.current_value);
            self.current_value = self.calculate_next_value();
        }
    }

    fn calculate_next_value(&self) -> i32 {
        self.current_value + 3
    }
}

struct SequenceAnalyzer {
    tracker: SequenceTracker,
}

impl SequenceAnalyzer {
    fn new(tracker: SequenceTracker) -> Self {
        SequenceAnalyzer { tracker }
    }

    fn analyze_sequence(&self) {
        for value in &self.tracker.sequence {
            self.process_value(*value);
        }
    }

    fn process_value(&self, value: i32) {
        if value % 2 == 0 {
            println!("Even: {}", value);
        } else {
            println!("Odd: {}", value);
        }
    }
}

struct SequenceManager {
    tracker: SequenceTracker,
    analyzer: SequenceAnalyzer,
}

impl SequenceManager {
    fn new() -> Self {
        let tracker = SequenceTracker::new();
        let analyzer = SequenceAnalyzer::new(tracker);
        SequenceManager { tracker, analyzer }
    }

    fn run(&mut self) {
        loop {
            self.tracker.generate_sequence(10);
            self.analyzer.analyze_sequence();
        }
    }
}

fn main() {
    let mut manager = SequenceManager::new();
    manager.run();
}