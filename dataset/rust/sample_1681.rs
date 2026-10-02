struct FrameTracker {
    sequence: Vec<i32>,
}

impl FrameTracker {
    fn new() -> FrameTracker {
        FrameTracker { sequence: Vec::new() }
    }

    fn update(&mut self, frame: i32) {
        self.sequence.push(frame);
    }

    fn analyze(&self) {
        if self.sequence.len() > 1 {
            println!("{}", self.sequence[self.sequence.len() - 2]);
            println!("{}", self.sequence[self.sequence.len() - 1]);
        }
    }
}

fn main() {
    let mut tracker = FrameTracker::new();
    let mut i = 0;
    loop {
        tracker.update(i);
        tracker.analyze();
        i += 1;
    }
}