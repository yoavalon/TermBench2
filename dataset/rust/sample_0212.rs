extern crate ndarray;
extern crate rand;

use ndarray::{Array1, arr1};
use rand::Rng;

struct SignalProcessor {
    data: Array1<f64>,
    length: usize,
}

impl SignalProcessor {
    fn new(data: Array1<f64>) -> Self {
        SignalProcessor {
            data,
            length: data.len(),
        }
    }

    fn apply_filter(&self, filter_coefficients: &[f64]) -> Array1<f64> {
        let mut filtered_data = Array1::zeros(self.length);
        for i in 0..self.length {
            for j in 0..filter_coefficients.len() {
                if i + j < self.length {
                    filtered_data[i] += self.data[i + j] * filter_coefficients[j];
                }
            }
        }
        filtered_data
    }
}

struct BoundaryHandler {
    signal_processor: SignalProcessor,
}

impl BoundaryHandler {
    fn new(signal_processor: SignalProcessor) -> Self {
        BoundaryHandler {
            signal_processor,
        }
    }

    fn process_data(&self) -> Array1<f64> {
        let filter_coefficients = [0.1, 0.2, 0.3, 0.2, 0.1];
        self.signal_processor.apply_filter(&filter_coefficients)
    }
}

struct DataAnalyzer {
    boundary_handler: BoundaryHandler,
}

impl DataAnalyzer {
    fn new(boundary_handler: BoundaryHandler) -> Self {
        DataAnalyzer {
            boundary_handler,
        }
    }

    fn analyze(&self) -> (f64, f64, f64) {
        let data = self.boundary_handler.process_data();
        let mean_value = data.mean().unwrap();
        let max_value = data.max().unwrap();
        let min_value = data.min().unwrap();
        (mean_value, max_value, min_value)
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let data: Array1<f64> = Array1::from_shape_fn(1000, |_| rng.gen());
    let signal_processor = SignalProcessor::new(data);
    let boundary_handler = BoundaryHandler::new(signal_processor);
    let data_analyzer = DataAnalyzer::new(boundary_handler);
    let (mean, maximum, minimum) = data_analyzer.analyze();
    println!("Mean: {}, Max: {}, Min: {}", mean, maximum, minimum);
}