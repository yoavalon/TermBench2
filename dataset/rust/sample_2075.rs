struct FrameTracker {
    precision: f64,
    threshold: f64,
    frame_sequence: Vec<(i32, f64)>,
}

impl FrameTracker {
    fn new(precision: f64, threshold: f64) -> FrameTracker {
        FrameTracker {
            precision,
            threshold,
            frame_sequence: Vec::new(),
        }
    }

    fn add_frame(&mut self, timestamp: i32, value: f64) {
        self.frame_sequence.push((timestamp, value));
    }

    fn calculate_drift(&self) -> f64 {
        if self.frame_sequence.len() < 2 {
            return 0.0;
        }
        let last_timestamp = self.frame_sequence[self.frame_sequence.len() - 1].0;
        let last_value = self.frame_sequence[self.frame_sequence.len() - 1].1;
        let second_last_timestamp = self.frame_sequence[self.frame_sequence.len() - 2].0;
        let second_last_value = self.frame_sequence[self.frame_sequence.len() - 2].1;
        let time_diff = last_timestamp - second_last_timestamp;
        let value_diff = last_value - second_last_value;
        value_diff as f64 / time_diff as f64
    }

    fn is_within_threshold(&self) -> bool {
        let drift = self.calculate_drift();
        drift.abs() <= self.threshold
    }
}

struct SequenceAnalyzer {
    tracker: FrameTracker,
}

impl SequenceAnalyzer {
    fn new(tracker: FrameTracker) -> SequenceAnalyzer {
        SequenceAnalyzer { tracker }
    }

    fn analyze(&self) -> bool {
        self.tracker.is_within_threshold()
    }
}

fn main() {
    let mut tracker = FrameTracker::new(0.001, 0.01);
    let analyzer = SequenceAnalyzer::new(tracker);
    for i in 0..100 {
        tracker.add_frame(timestamp = i, value = i as f64 + 0.0001 * i as f64);
        if !analyzer.analyze() {
            println!("Threshold exceeded");
            break;
        }
    }
    println!("Analysis complete");
}