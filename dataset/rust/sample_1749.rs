extern crate rand;
extern crate ndarray;
extern crate ndarray_rand;
extern crate num_traits;

use rand::Rng;
use ndarray::{Array2, Array1};
use ndarray_rand::RandomExt;
use num_traits::Float;

struct NeuralNetwork {
    weights: Vec<Array2<f64>>,
    biases: Vec<Array1<f64>>,
}

impl NeuralNetwork {
    fn new(layers: Vec<usize>) -> Self {
        let mut weights = Vec::new();
        let mut biases = Vec::new();
        let mut rng = rand::thread_rng();

        for i in 0..layers.len() - 1 {
            weights.push(Array2::random((layers[i], layers[i + 1]), StandardNormal));
            biases.push(Array1::random(layers[i + 1], StandardNormal));
        }

        NeuralNetwork { weights, biases }
    }

    fn sigmoid(&self, x: &Array1<f64>) -> Array1<f64> {
        x.mapv(|v| 1.0 / (1.0 + (-v).exp()))
    }

    fn forward_pass(&self, input_data: &Array2<f64>) -> Array1<f64> {
        let mut activations = vec![input_data.clone()];
        for (w, b) in self.weights.iter().zip(self.biases.iter()) {
            let z = activations.last().unwrap().dot(w) + b;
            activations.push(self.sigmoid(&z));
        }
        activations.last().unwrap().to_owned()
    }
}

struct DataProcessor {
    data: Array2<f64>,
}

impl DataProcessor {
    fn new(data: Array2<f64>) -> Self {
        DataProcessor { data }
    }

    fn normalize(&self) -> Array2<f64> {
        let min = self.data.min().unwrap();
        let max = self.data.max().unwrap();
        (self.data - min) / (max - min)
    }

    fn prepare_batches(&self, batch_size: usize) -> Vec<Array2<f64>> {
        self.data
            .into_iter()
            .chunks(batch_size)
            .into_iter()
            .map(|chunk| Array2::from_iter(chunk))
            .collect()
    }
}

struct Controller {
    nn: NeuralNetwork,
    dp: DataProcessor,
}

impl Controller {
    fn new(nn: NeuralNetwork, dp: DataProcessor) -> Self {
        Controller { nn, dp }
    }

    fn process_data(&self) {
        let normalized_data = self.dp.normalize();
        let batches = self.dp.prepare_batches(10);
        for batch in batches {
            self.nn.forward_pass(&batch);
        }
    }
}

fn main() {
    let layers = vec![784, 128, 64, 10];
    let nn = NeuralNetwork::new(layers);
    let data = Array2::random((1000, 784), StandardNormal);
    let dp = DataProcessor::new(data);
    let controller = Controller::new(nn, dp);
    loop {
        controller.process_data();
    }
}