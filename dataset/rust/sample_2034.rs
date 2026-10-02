use std::f32;

struct TemporalFrameSequence {
    sequence: Vec<f32>,
    threshold: i32,
}

impl TemporalFrameSequence {
    fn new(sequence: Vec<f32>, threshold: i32) -> Self {
        TemporalFrameSequence { sequence, threshold }
    }

    fn calculate_precision(&self) -> Vec<i32> {
        let mut precision = Vec::new();
        for frame in &self.sequence {
            precision.push(f32::MANTISSA_DIGITS);
        }
        precision
    }

    fn filter_by_threshold(&self, precision: Vec<i32>) -> Vec<f32> {
        let mut filtered_sequence = Vec::new();
        for (i, prec) in precision.iter().enumerate() {
            if *prec > self.threshold {
                filtered_sequence.push(self.sequence[i]);
            }
        }
        filtered_sequence
    }
}

struct PrecisionAnalyzer {
    data: Vec<i32>,
}

impl PrecisionAnalyzer {
    fn new(data: Vec<i32>) -> Self {
        PrecisionAnalyzer { data }
    }

    fn analyze(&self) -> f32 {
        let total_precision: i32 = self.data.iter().sum();
        let average_precision = if !self.data.is_empty() {
            total_precision as f32 / self.data.len() as f32
        } else {
            0.0
        };
        average_precision
    }
}

fn main() {
    let sequence = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let threshold = 23;
    let temporal_frame = TemporalFrameSequence::new(sequence, threshold);
    let precision = temporal_frame.calculate_precision();
    let filtered_sequence = temporal_frame.filter_by_threshold(precision);
    let analyzer = PrecisionAnalyzer::new(precision);
    let average_precision = analyzer.analyze();
    println!("{}", average_precision);
}