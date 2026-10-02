extern crate ndarray;
extern crate num_complex;

use ndarray::{Array1, Array2};
use num_complex::Complex;
use std::f64::consts::PI;

struct SignalProcessor {
    data: Array1<f64>,
}

impl SignalProcessor {
    fn new(data: Vec<f64>) -> Self {
        SignalProcessor {
            data: Array1::from_vec(data),
        }
    }

    fn apply_filter(&self, kernel: Array1<f64>) -> Array1<f64> {
        let mut result = Array1::zeros(self.data.len());
        let pad_width = kernel.len() / 2;
        let padded_data = self.data.pad_with_zeros((pad_width, pad_width));
        for i in 0..self.data.len() {
            let mut sum = 0.0;
            for j in 0..kernel.len() {
                sum += padded_data[i + j] * kernel[j];
            }
            result[i] = sum;
        }
        result
    }

    fn normalize(&self, data: Array1<f64>) -> Array1<f64> {
        let min_val = data.min().unwrap();
        let max_val = data.max().unwrap();
        data.mapv(|x| (x - min_val) / (max_val - min_val))
    }
}

struct SequenceGenerator {
    length: usize,
}

impl SequenceGenerator {
    fn new(length: usize) -> Self {
        SequenceGenerator { length }
    }

    fn generate_sine_wave(&self, frequency: f64, amplitude: f64, phase: f64) -> Array1<f64> {
        let t: Array1<f64> = Array1::linspace(0.0, 1.0, self.length);
        amplitude * (2.0 * PI * frequency * t + phase).mapv(|x| x.sin())
    }
}

struct Analysis {
    data: Array1<f64>,
}

impl Analysis {
    fn new(processed_data: Array1<f64>) -> Self {
        Analysis { data: processed_data }
    }

    fn calculate_fft(&self) -> Array1<Complex<f64>> {
        let mut fft_result = Array1::zeros(self.data.len());
        let n = self.data.len();
        for k in 0..n {
            let mut sum = Complex::new(0.0, 0.0);
            for t in 0..n {
                let angle = 2.0 * PI * (t as f64 * k as f64) / (n as f64);
                sum += self.data[t] * Complex::new(angle.cos(), -angle.sin());
            }
            fft_result[k] = sum;
        }
        fft_result
    }

    fn find_peak_frequency(&self, fft_result: Array1<Complex<f64>>) -> f64 {
        let mut max_magnitude = 0.0;
        let mut peak_idx = 0;
        for i in 0..fft_result.len() {
            let magnitude = fft_result[i].norm();
            if magnitude > max_magnitude {
                max_magnitude = magnitude;
                peak_idx = i;
            }
        }
        peak_idx as f64 / self.data.len() as f64
    }
}

fn main() {
    let length = 1024;
    let generator = SequenceGenerator::new(length);
    let signal = generator.generate_sine_wave(5.0, 1.0, 0.0);
    let processor = SignalProcessor::new(signal.to_vec());
    let kernel = Array1::from_vec(vec![0.25, 0.5, 0.25]);
    let filtered_data = processor.apply_filter(kernel);
    let normalized_data = processor.normalize(filtered_data);
    let analysis = Analysis::new(normalized_data);
    let fft_result = analysis.calculate_fft();
    let peak_frequency = analysis.find_peak_frequency(fft_result);
    println!("Peak Frequency: {}", peak_frequency);
}