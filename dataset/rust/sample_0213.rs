use ndarray::{Array1, arr1};
use ndarray::prelude::*;

struct SignalProcessor {
    data: Array1<f64>,
}

impl SignalProcessor {
    fn new(data: &[f64]) -> Self {
        SignalProcessor { data: arr1(data) }
    }

    fn apply_filter(&self, kernel: &[f64]) -> Array1<f64> {
        let kernel = arr1(kernel);
        let filtered_data = self.data.convolve(&kernel, WinType::Same, Boundary::Fill(0.0));
        filtered_data
    }

    fn normalize(&self, data: &Array1<f64>) -> Array1<f64> {
        let min_val = data.min().unwrap_or(0.0);
        let max_val = data.max().unwrap_or(0.0);
        if max_val == min_val {
            return data.clone();
        }
        (data - min_val) / (max_val - min_val)
    }
}

struct BoundaryHandler {
    processor: SignalProcessor,
}

impl BoundaryHandler {
    fn new(processor: SignalProcessor) -> Self {
        BoundaryHandler { processor }
    }

    fn handle_edges(&self, data: &Array1<f64>, mode: &str) -> Array1<f64> {
        let pad_width = 1;
        match mode {
            "reflect" => {
                let mut padded_data = data.to_owned();
                padded_data.insert_axis(Axis(0), 0);
                padded_data.push(Axis(0), 0.0);
                padded_data
            },
            _ => data.to_owned(),
        }
    }

    fn terminate_condition(&self, data: &Array1<f64>, threshold: f64) -> bool {
        data.iter().all(|&x| x < threshold)
    }
}

struct MainController {
    signal_processor: SignalProcessor,
    boundary_handler: BoundaryHandler,
}

impl MainController {
    fn new(signal_data: &[f64]) -> Self {
        let signal_processor = SignalProcessor::new(signal_data);
        let boundary_handler = BoundaryHandler::new(signal_processor.clone());
        MainController { signal_processor, boundary_handler }
    }

    fn process_signal(&mut self) -> Array1<f64> {
        let kernel = [1.0, 2.0, 1.0];
        let mut data = self.signal_processor.apply_filter(&kernel);
        data = self.boundary_handler.handle_edges(&data, "reflect");
        let mut normalized_data = self.signal_processor.normalize(&data);
        while !self.boundary_handler.terminate_condition(&normalized_data, 0.5) {
            data = self.signal_processor.apply_filter(&kernel);
            data = self.boundary_handler.handle_edges(&data, "reflect");
            normalized_data = self.signal_processor.normalize(&data);
        }
        normalized_data
    }
}

fn main() {
    let signal_data = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    let mut controller = MainController::new(&signal_data);
    let result = controller.process_signal();
    println!("{:?}", result);
}