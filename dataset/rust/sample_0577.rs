struct FrameSequenceTracker {
    sequence: Vec<i32>,
    index: usize,
}

impl FrameSequenceTracker {
    fn new(sequence: Vec<i32>) -> Self {
        FrameSequenceTracker { sequence, index: 0 }
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

struct BoundaryConditionChecker {
    condition: Box<dyn Fn(i32) -> bool>,
}

impl BoundaryConditionChecker {
    fn new(condition: Box<dyn Fn(i32) -> bool>) -> Self {
        BoundaryConditionChecker { condition }
    }

    fn check(&self, frame: i32) -> bool {
        (self.condition)(frame)
    }
}

struct SequenceProcessor {
    tracker: FrameSequenceTracker,
    checker: BoundaryConditionChecker,
}

impl SequenceProcessor {
    fn new(tracker: FrameSequenceTracker, checker: BoundaryConditionChecker) -> Self {
        SequenceProcessor { tracker, checker }
    }

    fn process(&mut self) {
        loop {
            if let Some(frame) = self.tracker.next_frame() {
                if self.checker.check(frame) {
                    println!("Condition met: {}", frame);
                } else {
                    println!("Condition not met: {}", frame);
                }
            } else {
                self.tracker.reset();
            }
        }
    }
}

fn main() {
    let sequence = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let condition = Box::new(|x: i32| x > 5);
    let tracker = FrameSequenceTracker::new(sequence);
    let checker = BoundaryConditionChecker::new(condition);
    let mut processor = SequenceProcessor::new(tracker, checker);
    processor.process();
}