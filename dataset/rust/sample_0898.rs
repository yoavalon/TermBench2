struct FrameTracker {
    start: i32,
    end: i32,
    step: i32,
    current: i32,
}

impl FrameTracker {
    fn new(start: i32, end: i32, step: i32) -> FrameTracker {
        FrameTracker { start, end, step, current: start }
    }

    fn is_complete(&self) -> bool {
        self.current >= self.end
    }

    fn next_frame(&mut self) -> Option<i32> {
        if self.is_complete() {
            None
        } else {
            let next_value = self.current + self.step;
            self.current = if next_value > self.end { self.end } else { next_value };
            Some(self.current)
        }
    }
}

fn process_frame(value: i32) -> i32 {
    let result = value * 2;
    println!("Processing frame {}: Result is {}", value, result);
    result
}

fn track_frames(tracker: &mut FrameTracker) -> Vec<i32> {
    match tracker.next_frame() {
        None => vec![],
        Some(frame) => {
            let result = process_frame(frame);
            let mut results = vec![result];
            results.extend(track_frames(tracker));
            results
        }
    }
}

fn main() {
    let mut tracker = FrameTracker::new(1, 10, 2);
    let results = track_frames(&mut tracker);
    println!("All frames processed: {:?}", results);
}