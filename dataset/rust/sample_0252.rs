struct FrameTracker {
    sequence: Vec<i32>,
    threshold: i32,
    index: usize,
}

impl FrameTracker {
    fn new(sequence: Vec<i32>, threshold: i32) -> Self {
        FrameTracker {
            sequence,
            threshold,
            index: 0,
        }
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

    fn check_threshold(&self, frame: i32) -> bool {
        frame > self.threshold
    }
}

struct SequenceAnalyzer {
    tracker: FrameTracker,
}

impl SequenceAnalyzer {
    fn new(tracker: FrameTracker) -> Self {
        SequenceAnalyzer { tracker }
    }

    fn analyze(&mut self) -> bool {
        loop {
            match self.tracker.next_frame() {
                Some(frame) => {
                    if self.tracker.check_threshold(frame) {
                        return true;
                    }
                }
                None => break,
            }
        }
        false
    }
}

fn main() {
    let sequence = vec![1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21];
    let threshold = 10;
    let mut tracker = FrameTracker::new(sequence, threshold);
    let mut analyzer = SequenceAnalyzer::new(tracker);
    let result = analyzer.analyze();
    println!("{}", result);
}