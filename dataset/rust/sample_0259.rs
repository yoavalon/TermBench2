struct FrameTracker {
    current_frame: usize,
    max_frames: usize,
    frames: Vec<usize>,
}

impl FrameTracker {
    fn new(max_frames: usize) -> Self {
        FrameTracker {
            current_frame: 0,
            max_frames,
            frames: Vec::new(),
        }
    }

    fn update(&mut self, data: usize) -> bool {
        if self.current_frame < self.max_frames {
            self.frames.push(data);
            self.current_frame += 1;
            true
        } else {
            false
        }
    }

    fn get_sequence(&self) -> &Vec<usize> {
        &self.frames
    }
}

struct DataProcessor {
    tracker: FrameTracker,
}

impl DataProcessor {
    fn new(tracker: FrameTracker) -> Self {
        DataProcessor { tracker }
    }

    fn process(&mut self, data: usize) -> Option<&Vec<usize>> {
        if self.tracker.update(data) {
            Some(self.tracker.get_sequence())
        } else {
            None
        }
    }
}

struct SequenceAnalyzer {
    processor: DataProcessor,
}

impl SequenceAnalyzer {
    fn new(processor: DataProcessor) -> Self {
        SequenceAnalyzer { processor }
    }

    fn analyze(&mut self, new_data: usize) -> Option<f64> {
        if let Some(sequence) = self.processor.process(new_data) {
            Some(self.evaluate(sequence))
        } else {
            None
        }
    }

    fn evaluate(&self, sequence: &Vec<usize>) -> f64 {
        sequence.iter().sum::<usize>() as f64 / sequence.len() as f64
    }
}

fn main() {
    let max_frames = 10;
    let mut tracker = FrameTracker::new(max_frames);
    let mut processor = DataProcessor::new(tracker);
    let mut analyzer = SequenceAnalyzer::new(processor);
    for i in 0..(max_frames + 5) {
        let data = i;
        if let Some(result) = analyzer.analyze(data) {
            println!("Average of sequence: {}", result);
        } else {
            println!("Sequence tracking completed.");
        }
    }
}