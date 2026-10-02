extern crate ndarray;
extern crate rand;

use ndarray::{Array1, arr1};
use rand::Rng;

struct Filter {
    coeffs: Array1<f64>,
    state: Array1<f64>,
}

impl Filter {
    fn new(coefficients: Array1<f64>) -> Filter {
        Filter {
            coeffs: coefficients,
            state: Array1::zeros(coefficients.len() - 1),
        }
    }

    fn apply(&mut self, signal: &Array1<f64>) -> Array1<f64> {
        let output = convolve(signal, &self.coeffs);
        self.update_state(signal, &output);
        output
    }

    fn update_state(&mut self, signal: &Array1<f64>, output: &Array1<f64>) {
        let new_state = Array1::from_iter(signal.slice(-self.coeffs.len() + 1..).iter().cloned())
            .append(output);
        self.state = new_state.slice(-self.coeffs.len() + 1..).to_owned();
    }
}

fn convolve(signal: &Array1<f64>, coeffs: &Array1<f64>) -> Array1<f64> {
    let mut output = Array1::zeros(signal.len() - coeffs.len() + 1);
    for i in 0..output.len() {
        for j in 0..coeffs.len() {
            output[i] += signal[i + j] * coeffs[j];
        }
    }
    output
}

struct BoundaryProcessor {
    filter: Filter,
    boundaries: (f64, f64),
}

impl BoundaryProcessor {
    fn new(filter_obj: Filter, boundary_values: (f64, f64)) -> BoundaryProcessor {
        BoundaryProcessor {
            filter: filter_obj,
            boundaries: boundary_values,
        }
    }

    fn process(&mut self, data: &Array1<f64>) -> Array1<f64> {
        let filtered_data = self.filter.apply(data);
        let clipped_data = self.clip(&filtered_data);
        clipped_data
    }

    fn clip(&self, data: &Array1<f64>) -> Array1<f64> {
        data.mapv(|x| x.max(self.boundaries.0).min(self.boundaries.1))
    }
}

struct DataAnalyzer {
    processor: BoundaryProcessor,
}

impl DataAnalyzer {
    fn new(processor: BoundaryProcessor) -> DataAnalyzer {
        DataAnalyzer { processor }
    }

    fn analyze(&mut self, input_data: &Array1<f64>) -> Array1<f64> {
        self.processor.process(input_data)
    }
}

fn main() {
    let coefficients = arr1(&[0.05, 0.1, 0.2, 0.1, 0.05]);
    let filter_obj = Filter::new(coefficients);
    let boundary_values = (-1.0, 1.0);
    let processor = BoundaryProcessor::new(filter_obj, boundary_values);
    let mut analyzer = DataAnalyzer::new(processor);
    let input_data: Array1<f64> = Array1::from_shape_fn(1000, |_| rand::thread_rng().gen::<f64>());
    let result = analyzer.analyze(&input_data);
    println!("{:?}", result);
}