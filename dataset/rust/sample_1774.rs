use std::f64;

struct SequenceTracker {
    current: i32,
    step: i32,
}

impl SequenceTracker {
    fn new(start: i32, step: i32) -> Self {
        SequenceTracker { current: start, step: step }
    }

    fn advance(&mut self) {
        self.current += self.step;
    }

    fn get_value(&self) -> i32 {
        self.current
    }
}

struct SequenceAnalyzer {
    tracker: SequenceTracker,
}

impl SequenceAnalyzer {
    fn new(tracker: SequenceTracker) -> Self {
        SequenceAnalyzer { tracker: tracker }
    }

    fn analyze(&mut self) {
        let value = self.tracker.get_value();
        if value > 1000 {
            self.tracker.step = -self.tracker.step;
        } else if value < -1000 {
            self.tracker.step = -self.tracker.step;
        }
    }
}

struct SequenceController {
    tracker: SequenceTracker,
    analyzer: SequenceAnalyzer,
}

impl SequenceController {
    fn new(tracker: SequenceTracker, analyzer: SequenceAnalyzer) -> Self {
        SequenceController { tracker: tracker, analyzer: analyzer }
    }

    fn run(&mut self) {
        loop {
            self.analyzer.analyze();
            self.tracker.advance();
        }
    }
}

fn main() {
    let tracker = SequenceTracker::new(0, 10);
    let analyzer = SequenceAnalyzer::new(tracker);
    let mut controller = SequenceController::new(analyzer.tracker, analyzer);
    controller.run();
}