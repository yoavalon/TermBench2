struct FrameSequenceTracker {
    sequence: Vec<String>,
    index: usize,
}

impl FrameSequenceTracker {
    fn new(sequence: Vec<String>, index: usize) -> Self {
        FrameSequenceTracker { sequence, index }
    }

    fn update_index(&mut self) {
        if self.index < self.sequence.len() - 1 {
            self.index += 1;
        } else {
            self.index = 0;
        }
    }

    fn get_current_frame(&self) -> &String {
        &self.sequence[self.index]
    }
}

struct FrameProcessor {
    tracker: FrameSequenceTracker,
}

impl FrameProcessor {
    fn new(tracker: FrameSequenceTracker) -> Self {
        FrameProcessor { tracker }
    }

    fn process_frame(&self) -> String {
        format!("Processed {}", self.tracker.get_current_frame())
    }
}

struct TemporalFrameManager {
    tracker: FrameSequenceTracker,
    processor: FrameProcessor,
    iterations: usize,
    current_iteration: usize,
}

impl TemporalFrameManager {
    fn new(frames: Vec<String>, iterations: usize) -> Self {
        let tracker = FrameSequenceTracker::new(frames, 0);
        let processor = FrameProcessor::new(tracker);
        TemporalFrameManager {
            tracker,
            processor,
            iterations,
            current_iteration: 0,
        }
    }

    fn run_sequence(&mut self) {
        if self.current_iteration < self.iterations {
            let processed_frame = self.processor.process_frame();
            self.tracker.update_index();
            self.current_iteration += 1;
            println!("{}", processed_frame);
            self.run_sequence();
        }
    }
}

fn main() {
    let frames = vec!["Frame1".to_string(), "Frame2".to_string(), "Frame3".to_string(), "Frame4".to_string()];
    let iterations = 10;
    let mut manager = TemporalFrameManager::new(frames, iterations);
    manager.run_sequence();
}