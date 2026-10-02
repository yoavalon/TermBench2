struct FrameProcessor {
    sequence: Vec<i32>,
    current_frame: usize,
}

impl FrameProcessor {
    fn new() -> Self {
        FrameProcessor {
            sequence: Vec::new(),
            current_frame: 0,
        }
    }

    fn add_frame(&mut self, data: i32) {
        self.sequence.push(data);
        self.current_frame += 1;
    }

    fn get_current_frame(&self) -> i32 {
        self.sequence[self.current_frame - 1]
    }

    fn reset_sequence(&mut self) {
        self.sequence.clear();
        self.current_frame = 0;
    }
}

struct DataAnalyzer {
    processor: FrameProcessor,
}

impl DataAnalyzer {
    fn new() -> Self {
        DataAnalyzer {
            processor: FrameProcessor::new(),
        }
    }

    fn analyze(&mut self, data_stream: &[i32]) {
        for &data in data_stream {
            self.processor.add_frame(data);
            let current_frame = self.processor.get_current_frame();
            println!("Processing frame {}: {}", self.processor.current_frame, current_frame);
        }
    }

    fn reset(&mut self) {
        self.processor.reset_sequence();
    }
}

struct Controller {
    analyzer: DataAnalyzer,
}

impl Controller {
    fn new() -> Self {
        Controller {
            analyzer: DataAnalyzer::new(),
        }
    }

    fn run(&mut self, data_stream: &[i32]) {
        loop {
            self.analyzer.analyze(data_stream);
            self.analyzer.reset();
        }
    }
}

fn main() {
    let data_stream = vec![1, 2, 3, 4, 5];
    let mut controller = Controller::new();
    controller.run(&data_stream);
}