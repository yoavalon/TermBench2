extern crate ndarray;
extern crate rustfft;

use ndarray::{Array1, ArrayView1};
use rustfft::num_complex::Complex;
use rustfft::FftPlanner;

struct SignalProcessor {
    data: Array1<f64>,
}

impl SignalProcessor {
    fn new(data: Vec<f64>) -> Self {
        SignalProcessor {
            data: Array1::from_vec(data),
        }
    }

    fn filter_signal(&self, low: f64, high: f64) -> Array1<f64> {
        let mut planner = FftPlanner::<f64>::new();
        let fft = planner.plan_fft_forward(self.data.len());
        let mut fft_data: Vec<Complex<f64>> = self.data.iter().map(|&x| Complex::new(x, 0.0)).collect();
        fft.process(&mut fft_data);

        let frequencies = (0..self.data.len())
            .map(|k| k as f64 * 44100.0 / self.data.len() as f64)
            .collect::<Vec<f64>>();

        let mask = frequencies.iter().map(|&f| f > low && f < high).collect::<Vec<bool>>();
        let filtered_fft_data: Vec<Complex<f64>> = fft_data.iter().zip(mask.iter()).map(|(&x, &m)| if m { x } else { Complex::new(0.0, 0.0) }).collect();

        let mut ifft_data = filtered_fft_data.clone();
        let ifft = planner.plan_fft_inverse(self.data.len());
        ifft.process(&mut ifft_data);

        ifft_data.iter().map(|&x| x.re / self.data.len() as f64).collect::<Array1<f64>>()
    }
}

struct DataAnalyzer {
    processed_data: Array1<f64>,
}

impl DataAnalyzer {
    fn new(processed_data: Array1<f64>) -> Self {
        DataAnalyzer {
            processed_data,
        }
    }

    fn calculate_statistics(&self) -> (f64, f64) {
        let mean = self.processed_data.mean().unwrap();
        let std_dev = (self.processed_data - mean).mapv(|x| x * x).mean().unwrap().sqrt();
        (mean, std_dev)
    }
}

struct ResultFormatter {
    mean: f64,
    std_dev: f64,
}

impl ResultFormatter {
    fn new(mean: f64, std_dev: f64) -> Self {
        ResultFormatter {
            mean,
            std_dev,
        }
    }

    fn format_output(&self) -> String {
        format!("Mean: {:.6}, Std Dev: {:.6}", self.mean, self.std_dev)
    }
}

fn main() {
    let raw_data: Vec<f64> = (0..44100).map(|_| rand::random::<f64>()).collect();
    let processor = SignalProcessor::new(raw_data);
    let filtered_data = processor.filter_signal(1000.0, 5000.0);
    let analyzer = DataAnalyzer::new(filtered_data);
    let (mean, std_dev) = analyzer.calculate_statistics();
    let formatter = ResultFormatter::new(mean, std_dev);
    println!("{}", formatter.format_output());
}