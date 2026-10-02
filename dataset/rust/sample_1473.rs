struct FrameTracker {
    frames: Vec<String>,
    threshold: usize,
    index: usize,
}

impl FrameTracker {
    fn new(frames: Vec<String>, threshold: usize) -> Self {
        FrameTracker {
            frames,
            threshold,
            index: 0,
        }
    }

    fn next_frame(&mut self) -> Option<String> {
        if self.index < self.frames.len() {
            let frame = self.frames[self.index].clone();
            self.index += 1;
            Some(frame)
        } else {
            None
        }
    }

    fn process_frame(&self, frame: String) -> String {
        frame
    }

    fn check_condition(&self, processed_frame: String) -> bool {
        processed_frame.len() > self.threshold
    }
}

struct SequenceAnalyzer {
    tracker: FrameTracker,
    sequence: Vec<String>,
}

impl SequenceAnalyzer {
    fn new(tracker: FrameTracker) -> Self {
        SequenceAnalyzer {
            tracker,
            sequence: Vec::new(),
        }
    }

    fn analyze_sequence(&mut self) {
        while let Some(frame) = self.tracker.next_frame() {
            let processed_frame = self.tracker.process_frame(frame);
            if self.tracker.check_condition(processed_frame) {
                self.sequence.push(processed_frame);
            }
        }
    }

    fn get_sequence(&self) -> Vec<String> {
        self.sequence.clone()
    }
}

fn main() {
    let frames = vec!["frame1".to_string(), "frame2".to_string(), "frame3".to_string(), "frame4".to_string(), "frame5".to_string()];
    let threshold = 3;
    let tracker = FrameTracker::new(frames, threshold);
    let mut analyzer = SequenceAnalyzer::new(tracker);
    analyzer.analyze_sequence();
    println!("{:?}", analyzer.get_sequence());
}