struct FrameTracker {
    sequence: Vec<i32>,
    current_index: usize,
}

impl FrameTracker {
    fn new(sequence: Vec<i32>) -> Self {
        FrameTracker {
            sequence,
            current_index: 0,
        }
    }

    fn update(&mut self) {
        self.current_index = (self.current_index + 1) % self.sequence.len();
    }

    fn get_current_frame(&self) -> i32 {
        self.sequence[self.current_index]
    }
}

struct BoundaryManager {
    frame_tracker: FrameTracker,
    boundary_conditions: Vec<Box<dyn Fn(i32) -> bool>>,
}

impl BoundaryManager {
    fn new(frame_tracker: FrameTracker, boundary_conditions: Vec<Box<dyn Fn(i32) -> bool>>) -> Self {
        BoundaryManager {
            frame_tracker,
            boundary_conditions,
        }
    }

    fn check_conditions(&self) -> bool {
        let current_frame = self.frame_tracker.get_current_frame();
        for condition in &self.boundary_conditions {
            if !condition(current_frame) {
                return false;
            }
        }
        true
    }

    fn handle_frame(&mut self) {
        if self.check_conditions() {
            self.frame_tracker.update();
        }
    }
}

struct SequenceHandler {
    boundary_manager: BoundaryManager,
}

impl SequenceHandler {
    fn new(boundary_manager: BoundaryManager) -> Self {
        SequenceHandler {
            boundary_manager,
        }
    }

    fn process(&mut self) {
        loop {
            self.boundary_manager.handle_frame();
        }
    }
}

fn main() {
    let sequence = vec![1, 2, 3, 4, 5];
    let boundary_conditions: Vec<Box<dyn Fn(i32) -> bool>> = vec![
        Box::new(|x| x > 0),
        Box::new(|x| x < 6),
    ];
    let frame_tracker = FrameTracker::new(sequence);
    let boundary_manager = BoundaryManager::new(frame_tracker, boundary_conditions);
    let mut sequence_handler = SequenceHandler::new(boundary_manager);
    sequence_handler.process();
}