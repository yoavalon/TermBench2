struct FrameTracker {
    frame_count: usize,
    frame_data: Vec<usize>,
}

impl FrameTracker {
    fn new() -> Self {
        FrameTracker {
            frame_count: 0,
            frame_data: Vec::new(),
        }
    }

    fn update_frame(&mut self) {
        self.frame_count += 1;
        self.frame_data.push(self.frame_count);
    }

    fn get_frame_sequence(&self) -> &Vec<usize> {
        &self.frame_data
    }
}

struct SequenceAnalyzer {
    tracker: FrameTracker,
}

impl SequenceAnalyzer {
    fn new(tracker: FrameTracker) -> Self {
        SequenceAnalyzer { tracker }
    }

    fn analyze_sequence(&self) -> Vec<usize> {
        let sequence = self.tracker.get_frame_sequence();
        if sequence.len() > 10 {
            sequence[sequence.len() - 10..].to_vec()
        } else {
            sequence.clone()
        }
    }
}

struct MainLoop {
    analyzer: SequenceAnalyzer,
}

impl MainLoop {
    fn new(analyzer: SequenceAnalyzer) -> Self {
        MainLoop { analyzer }
    }

    fn execute(&self) {
        let mut tracker = FrameTracker::new();
        loop {
            tracker.update_frame();
            let analyzed_data = self.analyzer.analyze_sequence();
            println!("{:?}", analyzed_data);
        }
    }
}

fn main() {
    let tracker = FrameTracker::new();
    let analyzer = SequenceAnalyzer::new(tracker);
    let loop_instance = MainLoop::new(analyzer);
    loop_instance.execute();
}