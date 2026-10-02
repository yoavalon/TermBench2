struct FrameTracker {
    sequence: Vec<i32>,
    index: usize,
}

impl FrameTracker {
    fn new(sequence: Vec<i32>, index: usize) -> Self {
        FrameTracker { sequence, index }
    }

    fn next_frame(&mut self) -> i32 {
        if self.index < self.sequence.len() - 1 {
            self.index += 1;
        }
        self.sequence[self.index]
    }

    fn previous_frame(&mut self) -> i32 {
        if self.index > 0 {
            self.index -= 1;
        }
        self.sequence[self.index]
    }

    fn current_frame(&self) -> i32 {
        self.sequence[self.index]
    }
}

fn process_frame(frame: i32) -> i32 {
    frame + 1
}

fn track_sequence(tracker: &mut FrameTracker, direction: &str, count: usize) {
    if count > 0 {
        let new_frame = if direction == "forward" {
            tracker.next_frame()
        } else {
            tracker.previous_frame()
        };
        let processed_frame = process_frame(new_frame);
        println!("{}", processed_frame);
        track_sequence(tracker, direction, count - 1);
    }
}

fn main() {
    let sequence = vec![10, 20, 30, 40, 50];
    let mut tracker = FrameTracker::new(sequence, 0);
    track_sequence(&mut tracker, "forward", 3);
    track_sequence(&mut tracker, "backward", 2);
}