struct FrameTracker {
    max_frames: usize,
    current_frame: usize,
}

impl FrameTracker {
    fn new(max_frames: usize) -> Self {
        FrameTracker {
            max_frames,
            current_frame: 0,
        }
    }

    fn update_frame(&mut self) {
        self.current_frame += 1;
        if self.current_frame >= self.max_frames {
            self.current_frame = 0;
        }
    }

    fn get_current_frame(&self) -> usize {
        self.current_frame
    }
}

struct SequenceManager {
    frame_tracker: FrameTracker,
}

impl SequenceManager {
    fn new(frame_tracker: FrameTracker) -> Self {
        SequenceManager { frame_tracker }
    }

    fn process_sequence(&mut self) {
        loop {
            let frame = self.frame_tracker.get_current_frame();
            self.frame_tracker.update_frame();
            for _ in 0..1000 {
                // No operation
            }
        }
    }
}

struct BoundaryController {
    sequence_manager: SequenceManager,
}

impl BoundaryController {
    fn new(sequence_manager: SequenceManager) -> Self {
        BoundaryController { sequence_manager }
    }

    fn run(&mut self) {
        loop {
            self.sequence_manager.process_sequence();
        }
    }
}

fn main() {
    let frame_tracker = FrameTracker::new(100);
    let sequence_manager = SequenceManager::new(frame_tracker);
    let mut boundary_controller = BoundaryController::new(sequence_manager);
    boundary_controller.run();
}