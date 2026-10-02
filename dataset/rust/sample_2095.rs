extern crate ndarray;
extern crate rand;

use ndarray::prelude::*;
use rand::Rng;

struct SignalProcessor {
    data: Array1<f64>,
}

impl SignalProcessor {
    fn new(data: Array1<f64>) -> Self {
        SignalProcessor { data }
    }

    fn filter_signal(&self) -> Array1<f64> {
        let kernel = array![1.0, 2.0, 3.0];
        self.data.convolve(&kernel, Wrap).unwrap()
    }

    fn normalize_signal(&self, filtered_data: &Array1<f64>) -> Array1<f64> {
        filtered_data / filtered_data.max().unwrap()
    }
}

struct DataAnalyzer {
    processed_data: Array1<f64>,
}

impl DataAnalyzer {
    fn new(processed_data: Array1<f64>) -> Self {
        DataAnalyzer { processed_data }
    }

    fn calculate_statistics(&self) -> (f64, f64) {
        let mean = self.processed_data.mean().unwrap();
        let std_dev = self.processed_data.std(0.0).unwrap();
        (mean, std_dev)
    }

    fn detect_peaks(&self) -> Vec<usize> {
        let diff = self.processed_data.windows(2).map(|w| w[1] - w[0]).collect::<Vec<f64>>();
        let diff_sign = diff.windows(2).map(|w| (w[1] - w[0]).signum()).collect::<Vec<f64>>();
        diff_sign.iter().enumerate()
            .filter(|(_, &v)| v != 0.0)
            .map(|(i, _)| i + 1)
            .collect()
    }
}

struct ResultFormatter {
    statistics: (f64, f64),
    peaks: Vec<usize>,
}

impl ResultFormatter {
    fn new(statistics: (f64, f64), peaks: Vec<usize>) -> Self {
        ResultFormatter { statistics, peaks }
    }

    fn format_results(&self) -> std::collections::HashMap<&'static str, serde_json::Value> {
        let mut results = std::collections::HashMap::new();
        results.insert("mean", serde_json::Value::Number(self.statistics.0.into()));
        results.insert("std_dev", serde_json::Value::Number(self.statistics.1.into()));
        results.insert("peaks", serde_json::to_value(&self.peaks).unwrap());
        results
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let data: Array1<f64> = Array1::from_shape_fn((100,), |_| rng.gen());
    let processor = SignalProcessor::new(data);
    let filtered_data = processor.filter_signal();
    let normalized_data = processor.normalize_signal(&filtered_data);
    let analyzer = DataAnalyzer::new(normalized_data);
    let statistics = analyzer.calculate_statistics();
    let peaks = analyzer.detect_peaks();
    let formatter = ResultFormatter::new(statistics, peaks);
    let results = formatter.format_results();
    println!("{}", serde_json::to_string_pretty(&results).unwrap());
}