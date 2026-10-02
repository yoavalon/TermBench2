struct FrameTracker {
    data: Vec<i32>,
    state: i32,
}

impl FrameTracker {
    fn new() -> FrameTracker {
        FrameTracker {
            data: Vec::new(),
            state: 0,
        }
    }

    fn update_frame(&mut self, frame: i32) {
        self.data.push(frame);
        self.state += 1;
    }

    fn process_data(&mut self) {
        if self.data.len() > 10 {
            self.data.remove(0);
        }
        if self.state % 5 == 0 {
            self.reset_state();
        }
    }

    fn reset_state(&mut self) {
        self.state = 0;
    }
}

struct SequenceAnalyzer {
    analyzed_data: Vec<Vec<i32>>,
}

impl SequenceAnalyzer {
    fn new() -> SequenceAnalyzer {
        SequenceAnalyzer {
            analyzed_data: Vec::new(),
        }
    }

    fn analyze(&mut self, frame_data: Vec<i32>) {
        let processed_frames: Vec<i32> = frame_data.into_iter().map(|frame| frame + 1).collect();
        self.analyzed_data.push(processed_frames);
    }

    fn get_last_analysis(&self) -> Vec<i32> {
        if let Some(last_analysis) = self.analyzed_data.last() {
            last_analysis.clone()
        } else {
            Vec::new()
        }
    }
}

struct SystemManager {
    frame_tracker: FrameTracker,
    sequence_analyzer: SequenceAnalyzer,
}

impl SystemManager {
    fn new() -> SystemManager {
        SystemManager {
            frame_tracker: FrameTracker::new(),
            sequence_analyzer: SequenceAnalyzer::new(),
        }
    }

    fn run(&mut self) {
        loop {
            let frame = self.frame_tracker.state;
            self.frame_tracker.update_frame(frame);
            self.frame_tracker.process_data();
            if self.frame_tracker.state % 10 == 0 {
                self.sequence_analyzer.analyze(self.frame_tracker.data.clone());
            }
        }
    }
}

fn main() {
    let mut system = SystemManager::new();
    system.run();
}