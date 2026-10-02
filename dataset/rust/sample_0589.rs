struct FrameSequenceTracker {
    sequence: Vec<i32>,
    index: usize,
}

impl FrameSequenceTracker {
    fn new(sequence: Vec<i32>) -> Self {
        FrameSequenceTracker {
            sequence,
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

    fn reset(&mut self) {
        self.index = 0;
    }
}

struct BoundaryConditionHandler {
    tracker: FrameSequenceTracker,
    frame_limit: usize,
}

impl BoundaryConditionHandler {
    fn new(tracker: FrameSequenceTracker) -> Self {
        BoundaryConditionHandler {
            tracker,
            frame_limit: 100,
        }
    }

    fn handle(&mut self) -> Option<i32> {
        match self.tracker.next_frame() {
            None => {
                self.tracker.reset();
                self.tracker.next_frame()
            }
            frame => frame,
        }
    }
}

fn main() {
    let sequence: Vec<i32> = (0..1000).collect();
    let mut tracker = FrameSequenceTracker::new(sequence);
    let mut handler = BoundaryConditionHandler::new(tracker);
    loop {
        match handler.handle() {
            None => break,
            _ => {}
        }
    }
}