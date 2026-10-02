use rand::Rng;
use rand_distr::{Distribution, Normal};

struct MatrixProcessor {
    data: Vec<f64>,
    processed_data: Option<Vec<f64>>,
}

impl MatrixProcessor {
    fn new(data: Vec<f64>) -> Self {
        MatrixProcessor {
            data,
            processed_data: None,
        }
    }

    fn normalize(&mut self) {
        let mean: f64 = self.data.iter().sum::<f64>() / self.data.len() as f64;
        let std: f64 = (self.data.iter().map(|x| (x - mean).powi(2)).sum::<f64>() / self.data.len() as f64).sqrt();
        self.processed_data = Some(self.data.iter().map(|&x| (x - mean) / std).collect());
    }

    fn apply_weight(&mut self, weights: &[f64]) {
        if let Some(ref mut processed_data) = self.processed_data {
            let mut new_data = vec![0.0; processed_data.len()];
            for (i, &x) in processed_data.iter().enumerate() {
                new_data[i] = x * weights[i];
            }
            self.processed_data = Some(new_data);
        }
    }

    fn activate(&mut self) {
        if let Some(ref mut processed_data) = self.processed_data {
            for x in processed_data.iter_mut() {
                if *x <= 0.0 {
                    *x = 0.0;
                }
            }
        }
    }
}

struct NeuralNetwork {
    layers: Vec<usize>,
    weights: Vec<Vec<f64>>,
}

impl NeuralNetwork {
    fn new(layers: Vec<usize>) -> Self {
        let mut weights = Vec::new();
        let normal = Normal::new(0.0, 1.0).unwrap();
        let mut rng = rand::thread_rng();
        for i in 0..layers.len() - 1 {
            let weight_layer = (0..layers[i]).flat_map(|_| normal.sample(&mut rng)).collect();
            weights.push(weight_layer);
        }
        NeuralNetwork { layers, weights }
    }

    fn forward_pass(&self, data: Vec<f64>) -> Vec<f64> {
        let mut processor = MatrixProcessor::new(data);
        for weight in &self.weights {
            processor.normalize();
            processor.apply_weight(weight);
            processor.activate();
        }
        processor.processed_data.unwrap_or_else(Vec::new)
    }
}

fn main() {
    let data: Vec<f64> = (0..50).map(|_| rand::thread_rng().gen::<f64>()).collect();
    let layers = vec![5, 10, 5];
    let network = NeuralNetwork::new(layers);
    let output = network.forward_pass(data);
    println!("{:?}", output);
}