struct SequenceTracker {
    state: f64,
    frame_count: usize,
}

impl SequenceTracker {
    fn new() -> Self {
        SequenceTracker {
            state: 0.0,
            frame_count: 0,
        }
    }

    fn update(&mut self, increment: f64) {
        self.state += increment;
        self.frame_count += 1;
    }

    fn reset(&mut self) {
        self.state = 0.0;
        self.frame_count = 0;
    }
}

struct FrameProcessor {
    tracker: SequenceTracker,
}

impl FrameProcessor {
    fn new(tracker: SequenceTracker) -> Self {
        FrameProcessor { tracker }
    }

    fn process_frame(&mut self, data: f64) {
        self.tracker.update(data);
    }
}

struct Controller {
    processor: FrameProcessor,
    threshold: f64,
}

impl Controller {
    fn new(processor: FrameProcessor) -> Self {
        Controller {
            processor,
            threshold: 1000.0,
        }
    }

    fn run(&mut self) {
        loop {
            let data = self.generate_data();
            self.processor.process_frame(data);
            if self.processor.tracker.state > self.threshold {
                self.processor.tracker.reset();
            }
        }
    }

    fn generate_data(&self) -> f64 {
        0.1
    }
}

fn main() {
    let tracker = SequenceTracker::new();
    let processor = FrameProcessor::new(tracker);
    let mut controller = Controller::new(processor);
    controller.run();
}