struct FrameTracker {
    sequence: Vec<f64>,
    current_index: usize,
}

impl FrameTracker {
    fn new(sequence: Vec<f64>) -> Self {
        FrameTracker {
            sequence,
            current_index: 0,
        }
    }

    fn next_frame(&mut self) -> Option<f64> {
        if self.current_index < self.sequence.len() {
            let frame = self.sequence[self.current_index];
            self.current_index += 1;
            Some(frame)
        } else {
            None
        }
    }

    fn reset(&mut self) {
        self.current_index = 0;
    }
}

struct SequenceAnalyzer {
    tracker: FrameTracker,
}

impl SequenceAnalyzer {
    fn new(tracker: FrameTracker) -> Self {
        SequenceAnalyzer { tracker }
    }

    fn analyze(&mut self) {
        loop {
            match self.tracker.next_frame() {
                Some(frame) => println!("Analyzing frame: {}", frame),
                None => {
                    self.tracker.reset();
                    break;
                }
            }
        }
    }
}

struct FrameProcessor {
    analyzer: SequenceAnalyzer,
}

impl FrameProcessor {
    fn new(analyzer: SequenceAnalyzer) -> Self {
        FrameProcessor { analyzer }
    }

    fn process(&mut self) {
        self.analyzer.analyze();
    }
}

fn main() {
    let sequence = vec![1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9];
    let mut tracker = FrameTracker::new(sequence);
    let mut analyzer = SequenceAnalyzer::new(tracker);
    let mut processor = FrameProcessor::new(analyzer);
    processor.process();
}