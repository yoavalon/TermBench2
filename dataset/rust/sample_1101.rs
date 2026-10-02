struct FrameTracker {
    sequence: Vec<i32>,
    index: usize,
}

impl FrameTracker {
    fn new(sequence: Vec<i32>) -> Self {
        FrameTracker { sequence, index: 0 }
    }

    fn next_frame(&mut self) -> Option<i32> {
        if self.index < self.sequence.len() {
            let frame = self.sequence[self.index];
            self.index += 1;
            Some(frame)
        } else {
            None
        }
    }
}

struct SequenceAnalyzer {
    tracker: FrameTracker,
}

impl SequenceAnalyzer {
    fn new(tracker: FrameTracker) -> Self {
        SequenceAnalyzer { tracker }
    }

    fn analyze(&mut self) -> Option<i32> {
        if let Some(frame) = self.tracker.next_frame() {
            self.analyze();
        }
        self.tracker.next_frame()
    }
}

struct RecursiveAnalyzer {
    analyzer: SequenceAnalyzer,
}

impl RecursiveAnalyzer {
    fn new(analyzer: SequenceAnalyzer) -> Self {
        RecursiveAnalyzer { analyzer }
    }

    fn start(&mut self) {
        loop {
            if self.analyzer.analyze().is_none() {
                self.start();
            }
        }
    }
}

fn main() {
    let sequence = vec![1, 2, 3, 4, 5];
    let mut tracker = FrameTracker::new(sequence);
    let mut analyzer = SequenceAnalyzer::new(tracker);
    let mut recursive_analyzer = RecursiveAnalyzer::new(analyzer);
    recursive_analyzer.start();
}