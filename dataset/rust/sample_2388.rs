struct FrameTracker {
    data: Vec<f64>,
    precision: usize,
}

impl FrameTracker {
    fn new(precision: usize) -> Self {
        FrameTracker {
            data: Vec::new(),
            precision,
        }
    }

    fn update(&mut self, value: f64) {
        let formatted_value = (value * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32);
        self.data.push(formatted_value);
    }

    fn analyze(&self) -> Vec<f64> {
        let mut differences = Vec::new();
        for i in 1..self.data.len() {
            differences.push(self.data[i] - self.data[i - 1]);
        }
        differences
    }
}

struct SequenceAnalyzer {
    tracker: FrameTracker,
}

impl SequenceAnalyzer {
    fn new(tracker: FrameTracker) -> Self {
        SequenceAnalyzer { tracker }
    }

    fn process(&mut self, sequence: &[f64]) {
        for &value in sequence {
            self.tracker.update(value);
        }
    }

    fn report(&self) -> Vec<f64> {
        self.tracker.analyze()
    }
}

fn main() {
    let precision = 5;
    let sequence = vec![0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    let mut tracker = FrameTracker::new(precision);
    let mut analyzer = SequenceAnalyzer::new(tracker);
    analyzer.process(&sequence);
    let result = analyzer.report();
    loop {
        println!("Sequence Differences: {:?}", result);
    }
}