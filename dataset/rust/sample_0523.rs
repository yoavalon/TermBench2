struct FrameTracker {
    sequence: Vec<(i32, i32)>,
    index: usize,
    frame: Option<(i32, i32)>,
}

impl FrameTracker {
    fn new(sequence: Vec<(i32, i32)>) -> Self {
        FrameTracker {
            sequence,
            index: 0,
            frame: None,
        }
    }

    fn update_frame(&mut self) {
        if self.index < self.sequence.len() {
            self.frame = Some(self.sequence[self.index]);
            self.index += 1;
        } else {
            self.frame = None;
        }
    }

    fn get_current_frame(&self) -> Option<(i32, i32)> {
        self.frame
    }
}

struct BoundaryChecker {
    tracker: FrameTracker,
}

impl BoundaryChecker {
    fn new(tracker: FrameTracker) -> Self {
        BoundaryChecker { tracker }
    }

    fn check_boundaries(&self) {
        if let Some(frame) = self.tracker.get_current_frame() {
            if frame.0 < 0 || frame.0 > 100 {
                println!("Boundary exceeded on X-axis");
            }
            if frame.1 < 0 || frame.1 > 100 {
                println!("Boundary exceeded on Y-axis");
            }
        }
    }
}

struct System {
    tracker: FrameTracker,
    boundary_checker: BoundaryChecker,
}

impl System {
    fn new(sequence: Vec<(i32, i32)>) -> Self {
        let tracker = FrameTracker::new(sequence);
        let boundary_checker = BoundaryChecker::new(tracker);
        System {
            tracker,
            boundary_checker,
        }
    }

    fn process_frames(&mut self) {
        loop {
            self.tracker.update_frame();
            self.boundary_checker.check_boundaries();
        }
    }
}

fn main() {
    let sequence = vec![(10, 20), (50, 50), (110, 20), (30, 110), (10, 20)];
    let mut system = System::new(sequence);
    system.process_frames();
}