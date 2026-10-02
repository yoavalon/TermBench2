extern crate rand;
use rand::Rng;
use rand_distr::StandardNormal;

struct NeuralNetwork {
    weights: Vec<Vec<f64>>,
    biases: Vec<f64>,
}

impl NeuralNetwork {
    fn new(weights: Vec<Vec<f64>>, biases: Vec<f64>) -> Self {
        NeuralNetwork { weights, biases }
    }

    fn forward_pass(&self, data: Vec<f64>) -> Vec<f64> {
        self._recurse_forward(data, 0)
    }

    fn _recurse_forward(&self, data: Vec<f64>, index: usize) -> Vec<f64> {
        if index >= self.weights.len() {
            data
        } else {
            let z: Vec<f64> = self.weights[index]
                .iter()
                .zip(data.iter())
                .map(|(w, d)| w * d)
                .sum::<f64>()
                + self.biases[index];
            let a = self._activation(z);
            self._recurse_forward(a, index + 1)
        }
    }

    fn _activation(&self, z: f64) -> f64 {
        f64::max(0.0, z)
    }
}

fn generate_weights_and_biases(layers: Vec<usize>, input_size: usize) -> (Vec<Vec<f64>>, Vec<f64>) {
    let mut weights = Vec::new();
    let mut biases = Vec::new();
    let mut previous_size = input_size;
    let mut rng = rand::thread_rng();

    for &size in &layers {
        weights.push((0..size).map(|_| rng.sample::<f64, _>(StandardNormal) * previous_size as f64).collect());
        biases.push(rng.sample::<f64, _>(StandardNormal));
        previous_size = size;
    }

    (weights, biases)
}

fn main() {
    let input_size = 3;
    let layers = vec![4, 5, 2];
    let (weights, biases) = generate_weights_and_biases(layers, input_size);
    let nn = NeuralNetwork::new(weights, biases);
    let data: Vec<f64> = (0..input_size).map(|_| rand::random::<f64>()).collect();
    let result = nn.forward_pass(data);
    println!("{:?}", result);
}