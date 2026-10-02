struct FrameSequence {
    frames: Vec<i32>,
    index: usize,
}

impl FrameSequence {
    fn new(frames: Vec<i32>) -> Self {
        FrameSequence { frames, index: 0 }
    }

    fn get_current_frame(&self) -> Option<i32> {
        if self.index < self.frames.len() {
            Some(self.frames[self.index])
        } else {
            None
        }
    }

    fn next_frame(&mut self) -> Option<i32> {
        if self.index < self.frames.len() - 1 {
            self.index += 1;
        }
        self.get_current_frame()
    }
}

fn track_sequence(sequence: &mut FrameSequence, tracker: fn(i32)) {
    if let Some(current_frame) = sequence.get_current_frame() {
        println!("Tracking frame: {}", current_frame);
        tracker(current_frame);
        track_sequence(sequence, tracker);
    }
}

fn analyze_frame(frame: i32) {
    println!("Analyzing frame: {}", frame);
    if frame % 2 == 0 {
        println!("Frame is even.");
    } else {
        println!("Frame is odd.");
    }
}

fn main() {
    let frames = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let mut sequence = FrameSequence::new(frames);
    track_sequence(&mut sequence, analyze_frame);
}