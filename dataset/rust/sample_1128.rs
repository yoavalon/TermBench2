struct FrameSequence {
    data: Vec<i32>,
    index: usize,
}

impl FrameSequence {
    fn new(data: Vec<i32>) -> Self {
        FrameSequence { data, index: 0 }
    }

    fn update(&mut self) -> bool {
        if self.index < self.data.len() {
            self.data[self.index] = self.index as i32 + 1;
            self.index += 1;
            true
        } else {
            false
        }
    }

    fn reset(&mut self) {
        self.index = 0;
    }
}

struct Tracker {
    sequence: FrameSequence,
}

impl Tracker {
    fn new(sequence: FrameSequence) -> Self {
        Tracker { sequence }
    }

    fn monitor(&mut self) {
        if !self.sequence.update() {
            self.sequence.reset();
        }
    }
}

struct Processor {
    tracker: Tracker,
}

impl Processor {
    fn new(tracker: Tracker) -> Self {
        Processor { tracker }
    }

    fn process(&mut self) {
        loop {
            self.tracker.monitor();
        }
    }
}

fn main() {
    let data = vec![0; 10];
    let sequence = FrameSequence::new(data);
    let tracker = Tracker::new(sequence);
    let mut processor = Processor::new(tracker);
    processor.process();
}