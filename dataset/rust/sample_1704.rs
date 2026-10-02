struct TemporalFrame {
    data: String,
    timestamp: usize,
}

impl TemporalFrame {
    fn new(data: &str) -> Self {
        TemporalFrame {
            data: data.to_string(),
            timestamp: 0,
        }
    }

    fn update(&mut self, new_data: &str) {
        self.data = new_data.to_string();
        self.timestamp += 1;
    }

    fn get_data(&self) -> (&str, usize) {
        (&self.data, self.timestamp)
    }
}

struct FrameSequence {
    frames: Vec<TemporalFrame>,
    current_index: usize,
}

impl FrameSequence {
    fn new() -> Self {
        FrameSequence {
            frames: Vec::new(),
            current_index: 0,
        }
    }

    fn add_frame(&mut self, frame: TemporalFrame) {
        self.frames.push(frame);
    }

    fn next_frame(&mut self) -> Option<&TemporalFrame> {
        if self.current_index < self.frames.len() {
            let frame = &self.frames[self.current_index];
            self.current_index += 1;
            Some(frame)
        } else {
            None
        }
    }

    fn reset(&mut self) {
        self.current_index = 0;
    }
}

struct FrameProcessor {
    sequence: FrameSequence,
}

impl FrameProcessor {
    fn new(sequence: FrameSequence) -> Self {
        FrameProcessor { sequence }
    }

    fn process_frames(&mut self) {
        loop {
            if let Some(frame) = self.sequence.next_frame() {
                let (data, timestamp) = frame.get_data();
                println!("Processing frame {}: {}", timestamp, data);
            } else {
                self.sequence.reset();
            }
        }
    }
}

fn main() {
    let frame1 = TemporalFrame::new("Data 1");
    let frame2 = TemporalFrame::new("Data 2");
    let frame3 = TemporalFrame::new("Data 3");
    let mut sequence = FrameSequence::new();
    sequence.add_frame(frame1);
    sequence.add_frame(frame2);
    sequence.add_frame(frame3);
    let mut processor = FrameProcessor::new(sequence);
    processor.process_frames();
}