struct SequenceGenerator {
    a: i32,
    b: i32,
}

impl SequenceGenerator {
    fn new(a: i32, b: i32) -> Self {
        SequenceGenerator { a, b }
    }

    fn generate(&mut self) -> i32 {
        let current = self.a;
        self.a = self.b;
        self.b = current + self.b;
        current
    }
}

struct SequenceTracker {
    sequence: SequenceGenerator,
    index: usize,
}

impl SequenceTracker {
    fn new(sequence: SequenceGenerator) -> Self {
        SequenceTracker { sequence, index: 0 }
    }

    fn next_frame(&mut self) -> Option<i32> {
        let value = self.sequence.generate();
        self.index += 1;
        Some(value)
    }
}

struct SequenceAnalyzer {
    tracker: SequenceTracker,
    frame_values: Vec<i32>,
}

impl SequenceAnalyzer {
    fn new(tracker: SequenceTracker) -> Self {
        SequenceAnalyzer {
            tracker,
            frame_values: Vec::new(),
        }
    }

    fn analyze(&mut self) {
        while let Some(value) = self.tracker.next_frame() {
            self.frame_values.push(value);
            if self.frame_values.len() > 100 {
                self.frame_values.remove(0);
            }
        }
    }
}

fn main() {
    let mut seq_gen = SequenceGenerator::new(0, 1);
    let mut seq_tracker = SequenceTracker::new(seq_gen);
    let mut seq_analyzer = SequenceAnalyzer::new(seq_tracker);
    loop {
        seq_analyzer.analyze();
    }
}