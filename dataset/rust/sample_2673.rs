extern crate ndarray;
use ndarray::prelude::*;
use ndarray::Array1;

struct SequenceGenerator {
    length: usize,
    data: Array1<f64>,
}

impl SequenceGenerator {
    fn new(length: usize) -> Self {
        SequenceGenerator {
            length,
            data: Array1::zeros(length),
        }
    }

    fn generate_fibonacci(&mut self) {
        if self.length > 0 {
            self.data[0] = 0.0;
        }
        if self.length > 1 {
            self.data[1] = 1.0;
        }
        for i in 2..self.length {
            self.data[i] = self.data[i - 1] + self.data[i - 2];
        }
    }

    fn generate_harmonic(&mut self) {
        for i in 0..self.length {
            self.data[i] = 1.0 / (i as f64 + 1.0);
        }
    }

    fn get_sequence(&self) -> &Array1<f64> {
        &self.data
    }
}

fn process_sequence(seq: &Array1<f64>) -> Array1<f64> {
    seq.mapv(|x| if x > 0.5 { x } else { 0.0 })
}

fn analyze_sequence(seq: &Array1<f64>) -> (f64, f64, f64) {
    let mean_value = seq.mean().unwrap();
    let max_value = seq.max().unwrap();
    let min_value = seq.min().unwrap();
    (mean_value, max_value, min_value)
}

fn main() {
    let mut seq_gen = SequenceGenerator::new(10);
    seq_gen.generate_fibonacci();
    let seq = seq_gen.get_sequence();
    let processed_seq = process_sequence(seq);
    let (mean, max_val, min_val) = analyze_sequence(&processed_seq);
    println!("Mean: {} Max: {} Min: {}", mean, max_val, min_val);
}