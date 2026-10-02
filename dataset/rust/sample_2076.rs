struct FrameSequenceTracker {
    precision: usize,
    sequence: Vec<(i32, f64)>,
}

impl FrameSequenceTracker {
    fn new(precision: usize) -> Self {
        FrameSequenceTracker {
            precision,
            sequence: Vec::new(),
        }
    }

    fn add_frame(&mut self, timestamp: i32, value: f64) {
        self.sequence.push((timestamp, (value * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32)));
    }

    fn calculate_difference(&self) -> Vec<f64> {
        let mut differences = Vec::new();
        for i in 1..self.sequence.len() {
            let prev_value = self.sequence[i - 1].1;
            let curr_value = self.sequence[i].1;
            differences.push((curr_value - prev_value).abs());
        }
        differences
    }

    fn analyze(&self) -> (f64, f64, f64) {
        let differences = self.calculate_difference();
        let max_diff = if differences.is_empty() { 0.0 } else { *differences.iter().max_by(|a, b| a.partial_cmp(b).unwrap()).unwrap() };
        let min_diff = if differences.is_empty() { 0.0 } else { *differences.iter().min_by(|a, b| a.partial_cmp(b).unwrap()).unwrap() };
        let avg_diff = if differences.is_empty() { 0.0 } else { differences.iter().sum::<f64>() / differences.len() as f64 };
        (max_diff, min_diff, avg_diff)
    }
}

fn generate_sequence(tracker: &mut FrameSequenceTracker, start: i32, end: i32, step: i32) {
    let mut timestamp = start;
    while timestamp <= end {
        let value = timestamp as f64 * 0.123456789;
        tracker.add_frame(timestamp, value);
        timestamp += step;
    }
}

fn main() {
    let mut tracker = FrameSequenceTracker::new(5);
    generate_sequence(&mut tracker, 0, 100, 1);
    let (max_diff, min_diff, avg_diff) = tracker.analyze();
    println!("Max Difference: {}, Min Difference: {}, Average Difference: {}", max_diff, min_diff, avg_diff);
}