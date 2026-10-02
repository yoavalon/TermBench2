use rand::Rng;
use std::f64;

struct SignalProcessor {
    data: Vec<f64>,
    filter_coefficients: Vec<f64>,
}

impl SignalProcessor {
    fn new(data: Vec<f64>) -> Self {
        SignalProcessor {
            data,
            filter_coefficients: vec![0.2, 0.4, 0.4, 0.2],
        }
    }

    fn apply_filter(&self) -> Vec<f64> {
        let mut filtered_data = vec![0.0; self.data.len()];
        for i in 0..self.data.len() {
            let mut sum = 0.0;
            for j in 0..self.filter_coefficients.len() {
                let index = if i as isize - j as isize >= 0 {
                    (i as isize - j as isize) as usize
                } else {
                    0
                };
                sum += self.data[index] * self.filter_coefficients[j];
            }
            filtered_data[i] = sum;
        }
        filtered_data
    }
}

struct DataAnalyzer {
    data: Vec<f64>,
}

impl DataAnalyzer {
    fn new(data: Vec<f64>) -> Self {
        DataAnalyzer { data }
    }

    fn compute_statistics(&self) -> (f64, f64) {
        let mean = self.data.iter().sum::<f64>() / self.data.len() as f64;
        let variance = self.data.iter().map(|x| (x - mean).powi(2)).sum::<f64>() / self.data.len() as f64;
        (mean, variance)
    }
}

struct SignalTransformer {
    data: Vec<f64>,
}

impl SignalTransformer {
    fn new(data: Vec<f64>) -> Self {
        SignalTransformer { data }
    }

    fn normalize(&self) -> Vec<f64> {
        let max_val = self.data.iter().cloned().fold(f64::NEG_INFINITY, f64::max);
        let min_val = self.data.iter().cloned().fold(f64::INFINITY, f64::min);
        self.data.iter().map(|x| (x - min_val) / (max_val - min_val)).collect()
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let initial_data: Vec<f64> = (0..1000).map(|_| rng.gen()).collect();
    let mut processor = SignalProcessor::new(initial_data);
    let filtered_data = processor.apply_filter();
    let mut analyzer = DataAnalyzer::new(filtered_data);
    let (mut mean, mut variance) = analyzer.compute_statistics();
    let mut transformer = SignalTransformer::new(filtered_data);
    let mut normalized_data = transformer.normalize();

    loop {
        let new_data: Vec<f64> = (0..1000).map(|_| rng.gen()).collect();
        processor.data = new_data;
        processor.filter_coefficients = vec![0.1, 0.2, 0.3, 0.4];
        let filtered_data = processor.apply_filter();
        analyzer.data = filtered_data;
        (mean, variance) = analyzer.compute_statistics();
        transformer.data = filtered_data;
        normalized_data = transformer.normalize();
    }
}