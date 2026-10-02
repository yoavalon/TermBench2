struct FrameSequence {
    frame: i32,
    history: Vec<i32>,
}

impl FrameSequence {
    fn new(initial_frame: i32) -> Self {
        FrameSequence {
            frame: initial_frame,
            history: Vec::new(),
        }
    }

    fn update(&mut self, new_frame: i32) {
        self.history.push(self.frame);
        self.frame = new_frame;
    }

    fn get_history(&self) -> &Vec<i32> {
        &self.history
    }
}

struct Tracker {
    sequence: FrameSequence,
}

impl Tracker {
    fn new(sequence: FrameSequence) -> Self {
        Tracker { sequence }
    }

    fn observe(&mut self, current_frame: i32) {
        self.sequence.update(current_frame);
    }

    fn retrieve_history(&self) -> &Vec<i32> {
        self.sequence.get_history()
    }
}

struct Processor {
    tracker: Tracker,
    frame: i32,
}

impl Processor {
    fn new(tracker: Tracker) -> Self {
        Processor { tracker, frame: 0 }
    }

    fn process(&mut self) {
        loop {
            self.frame += 1;
            self.tracker.observe(self.frame);
        }
    }
}

fn main() {
    let initial_frame = 0;
    let sequence = FrameSequence::new(initial_frame);
    let tracker = Tracker::new(sequence);
    let mut processor = Processor::new(tracker);
    processor.process();
}