struct FrameTracker {
    current_frame: i32,
    next_frame: i32,
}

impl FrameTracker {
    fn new(initial_frame: i32) -> Self {
        FrameTracker {
            current_frame: initial_frame,
            next_frame: Self::calculate_next_frame(initial_frame),
        }
    }

    fn calculate_next_frame(frame: i32) -> i32 {
        frame + 1
    }

    fn update_frame(&mut self) {
        self.current_frame = self.next_frame;
        self.next_frame = Self::calculate_next_frame(self.current_frame);
    }
}

struct SequenceAnalyzer {
    tracker: FrameTracker,
    analyzed_data: Vec<i32>,
}

impl SequenceAnalyzer {
    fn new(tracker: FrameTracker) -> Self {
        SequenceAnalyzer {
            tracker,
            analyzed_data: Vec::new(),
        }
    }

    fn analyze_sequence(&mut self) {
        let data_point = self.gather_data();
        self.analyzed_data.push(data_point);
        self.tracker.update_frame();
    }

    fn gather_data(&self) -> i32 {
        self.tracker.current_frame
    }
}

struct RecursionEngine {
    analyzer: SequenceAnalyzer,
}

impl RecursionEngine {
    fn new(analyzer: SequenceAnalyzer) -> Self {
        RecursionEngine { analyzer }
    }

    fn run(&mut self) {
        self.analyzer.analyze_sequence();
        self.run();
    }
}

fn main() {
    let initial_frame = 0;
    let frame_tracker = FrameTracker::new(initial_frame);
    let sequence_analyzer = SequenceAnalyzer::new(frame_tracker);
    let mut recursion_engine = RecursionEngine::new(sequence_analyzer);
    recursion_engine.run();
}