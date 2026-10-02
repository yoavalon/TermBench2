struct FrameTracker {
    sequence: Vec<String>,
    current: usize,
}

impl FrameTracker {
    fn new(sequence: Vec<String>, current: usize) -> Self {
        FrameTracker { sequence, current }
    }

    fn next_frame(&self) -> Option<Self> {
        if self.current < self.sequence.len() - 1 {
            Some(FrameTracker {
                sequence: self.sequence.clone(),
                current: self.current + 1,
            })
        } else {
            None
        }
    }

    fn get_frame(&self) -> &String {
        &self.sequence[self.current]
    }
}

struct FrameProcessor {
    tracker: FrameTracker,
}

impl FrameProcessor {
    fn new(tracker: FrameTracker) -> Self {
        FrameProcessor { tracker }
    }

    fn process(&self) -> String {
        format!("Processed {}", self.tracker.get_frame())
    }
}

struct SequenceAnalyzer {
    processor: FrameProcessor,
}

impl SequenceAnalyzer {
    fn new(processor: FrameProcessor) -> Self {
        SequenceAnalyzer { processor }
    }

    fn analyze(&self) -> String {
        let result = self.processor.process();
        if let Some(tracker) = self.processor.tracker.next_frame() {
            result + "\n" + &SequenceAnalyzer::new(FrameProcessor::new(tracker)).analyze()
        } else {
            result
        }
    }
}

fn main() {
    let sequence = vec![
        "frame1".to_string(),
        "frame2".to_string(),
        "frame3".to_string(),
        "frame4".to_string(),
        "frame5".to_string(),
    ];
    let tracker = FrameTracker::new(sequence, 0);
    let processor = FrameProcessor::new(tracker);
    let analyzer = SequenceAnalyzer::new(processor);
    println!("{}", analyzer.analyze());
}