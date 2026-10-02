use std::f64::consts::PI;

struct SignalProcessor {
    data: Vec<f64>,
}

impl SignalProcessor {
    fn new(data: Vec<f64>) -> Self {
        SignalProcessor { data }
    }

    fn apply_filter(&self, kernel: &[f64]) -> Vec<f64> {
        let mut result = vec![0.0; self.data.len()];
        let kernel_len = kernel.len();
        for i in 0..self.data.len() {
            for j in 0..kernel_len {
                if i + j < self.data.len() {
                    result[i] += self.data[i + j] * kernel[j];
                }
            }
        }
        result
    }

    fn normalize(&self, data: &[f64]) -> Vec<f64> {
        let min_val = data.iter().fold(f64::INFINITY, |a, &b| a.min(b));
        let max_val = data.iter().fold(f64::NEG_INFINITY, |a, &b| a.max(b));
        data.iter().map(|&x| (x - min_val) / (max_val - min_val)).collect()
    }
}

struct SequenceGenerator {
    length: usize,
    amplitude: f64,
}

impl SequenceGenerator {
    fn new(length: usize, amplitude: f64) -> Self {
        SequenceGenerator { length, amplitude }
    }

    fn generate_sine_wave(&self) -> Vec<f64> {
        (0..self.length)
            .map(|i| self.amplitude * (2.0 * PI * i as f64 / self.length as f64).sin())
            .collect()
    }

    fn generate_square_wave(&self) -> Vec<f64> {
        (0..self.length)
            .map(|i| self.amplitude * ((2.0 * PI * i as f64 / self.length as f64).sin()).signum())
            .collect()
    }
}

fn main() {
    let seq_gen = SequenceGenerator::new(100, 1.0);
    let sine_wave = seq_gen.generate_sine_wave();
    let square_wave = seq_gen.generate_square_wave();
    let mut processor = SignalProcessor::new(sine_wave);
    let filtered_sine = processor.apply_filter(&[0.25, 0.5, 0.25]);
    let normalized_sine = processor.normalize(&filtered_sine);
    processor.data = square_wave;
    let filtered_square = processor.apply_filter(&[-0.25, 0.5, -0.25]);
    let normalized_square = processor.normalize(&filtered_square);
    println!("Normalized Sine Wave: {:?}", normalized_sine);
    println!("Normalized Square Wave: {:?}", normalized_square);
}