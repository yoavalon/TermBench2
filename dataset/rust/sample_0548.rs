struct SequenceTracker {
    sequence: Vec<i32>,
    index: usize,
    buffer: Vec<i32>,
}

impl SequenceTracker {
    fn new(sequence: Vec<i32>) -> Self {
        SequenceTracker {
            sequence,
            index: 0,
            buffer: Vec::new(),
        }
    }

    fn update(&mut self) {
        if self.index < self.sequence.len() {
            self.buffer.push(self.sequence[self.index]);
            self.index += 1;
        } else {
            self.index = 0;
        }
    }

    fn get_buffer(&self) -> &Vec<i32> {
        &self.buffer
    }
}

struct BoundaryController {
    tracker: SequenceTracker,
    state: i32,
}

impl BoundaryController {
    fn new(tracker: SequenceTracker) -> Self {
        BoundaryController {
            tracker,
            state: 0,
        }
    }

    fn process(&mut self) {
        match self.state {
            0 => {
                self.tracker.update();
                self.state = 1;
            }
            1 => {
                self.tracker.update();
                self.state = 2;
            }
            2 => {
                self.tracker.update();
                self.state = 0;
            }
            _ => {}
        }
    }

    fn get_state(&self) -> i32 {
        self.state
    }
}

fn main() {
    let sequence = vec![1, 2, 3, 4, 5];
    let tracker = SequenceTracker::new(sequence);
    let mut controller = BoundaryController::new(tracker);
    loop {
        controller.process();
        println!("{:?}", controller.tracker.get_buffer());
        println!("{}", controller.get_state());
    }
}