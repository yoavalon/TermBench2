use std::collections::VecDeque;
use std::time::SystemTime;
use std::fmt::Write;

struct FrameTracker {
    frames: VecDeque<String>,
    current_frame: usize,
}

impl FrameTracker {
    fn new() -> Self {
        FrameTracker {
            frames: VecDeque::new(),
            current_frame: 0,
        }
    }

    fn add_frame(&mut self, data: String) {
        self.frames.push_back(data);
        self.current_frame = self.frames.len() - 1;
    }

    fn get_current_frame(&self) -> &str {
        &self.frames[self.current_frame]
    }

    fn advance_frame(&mut self) -> &str {
        if self.current_frame < self.frames.len() - 1 {
            self.current_frame += 1;
        }
        self.get_current_frame()
    }

    fn rewind_frame(&mut self) -> &str {
        if self.current_frame > 0 {
            self.current_frame -= 1;
        }
        self.get_current_frame()
    }
}

struct DataMutator {
    tracker: FrameTracker,
}

impl DataMutator {
    fn new(tracker: FrameTracker) -> Self {
        DataMutator { tracker }
    }

    fn mutate(&self, data: &mut serde_json::Value) -> serde_json::Value {
        let now = SystemTime::now()
            .duration_since(SystemTime::UNIX_EPOCH)
            .expect("Time went backwards")
            .as_secs();
        data["timestamp"] = serde_json::Value::String(now.to_string());
        data.clone()
    }
}

fn main() {
    let mut tracker = FrameTracker::new();
    let mutator = DataMutator::new(tracker);
    for i in 0..10 {
        let mut frame_data = serde_json::json!({
            "id": i,
            "value": i * 10
        });
        let mutated_data = mutator.mutate(&mut frame_data);
        let data_str = mutated_data.to_string();
        tracker.add_frame(data_str);
    }
    loop {
        let current_frame = tracker.get_current_frame();
        println!("Current Frame: {}", current_frame);
        if tracker.advance_frame() == current_frame {
            tracker.rewind_frame();
        }
    }
}