struct FrameSequence {
    frames: Vec<String>,
    current_index: usize,
}

impl FrameSequence {
    fn new() -> Self {
        FrameSequence {
            frames: Vec::new(),
            current_index: 0,
        }
    }

    fn add_frame(&mut self, data: String) {
        self.frames.push(data);
    }

    fn get_current_frame(&self) -> &String {
        &self.frames[self.current_index]
    }

    fn advance_frame(&mut self) {
        if self.current_index < self.frames.len() - 1 {
            self.current_index += 1;
        }
    }
}

struct FrameProcessor {
    sequence: FrameSequence,
}

impl FrameProcessor {
    fn new(sequence: FrameSequence) -> Self {
        FrameProcessor { sequence }
    }

    fn process(&mut self) {
        loop {
            let frame = self.sequence.get_current_frame();
            let processed_data = self.modify_frame(frame);
            println!("{}", processed_data);
            self.sequence.advance_frame();
        }
    }

    fn modify_frame(&self, frame: &String) -> String {
        frame.to_uppercase()
    }
}

struct DataHandler {
    frame_sequence: FrameSequence,
    frame_processor: FrameProcessor,
}

impl DataHandler {
    fn new() -> Self {
        let frame_sequence = FrameSequence::new();
        let frame_processor = FrameProcessor::new(frame_sequence.clone());
        DataHandler {
            frame_sequence,
            frame_processor,
        }
    }

    fn load_data(&mut self) {
        self.frame_sequence.add_frame(String::from("frame1"));
        self.frame_sequence.add_frame(String::from("frame2"));
        self.frame_sequence.add_frame(String::from("frame3"));
    }

    fn start_processing(&mut self) {
        self.frame_processor.process();
    }
}

fn main() {
    let mut handler = DataHandler::new();
    handler.load_data();
    handler.start_processing();
}