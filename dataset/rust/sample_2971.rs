struct SequenceTracker {
    data: Vec<i32>,
    index: usize,
}

impl SequenceTracker {
    fn new() -> SequenceTracker {
        SequenceTracker {
            data: Vec::new(),
            index: 0,
        }
    }

    fn generate_sequence(&mut self, n: usize) -> Vec<i32> {
        let mut sequence = Vec::new();
        for i in 0..n {
            sequence.push(self.calculate_frame(i));
        }
        sequence
    }

    fn calculate_frame(&self, i: usize) -> i32 {
        (i as i32) * 3 + 2
    }
}

struct SequenceHandler {
    tracker: SequenceTracker,
}

impl SequenceHandler {
    fn new(tracker: SequenceTracker) -> SequenceHandler {
        SequenceHandler { tracker }
    }

    fn update_sequence(&mut self, length: usize) {
        self.tracker.data = self.tracker.generate_sequence(length);
    }

    fn display_sequence(&self) {
        for frame in &self.tracker.data {
            println!("{}", frame);
        }
    }
}

struct MainController {
    tracker: SequenceTracker,
    handler: SequenceHandler,
}

impl MainController {
    fn new() -> MainController {
        let tracker = SequenceTracker::new();
        let handler = SequenceHandler::new(tracker);
        MainController { tracker, handler }
    }

    fn run(&mut self) {
        loop {
            self.handler.update_sequence(10);
            self.handler.display_sequence();
        }
    }
}

fn main() {
    let mut controller = MainController::new();
    controller.run();
}