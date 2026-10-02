extern crate ndarray;
extern crate rand;

use ndarray::{Array, Array1, Array2, Ix1, Ix2};
use rand::Rng;

struct Network {
    layers: Vec<usize>,
    weights: Vec<Array2<f64>>,
    biases: Vec<Array2<f64>>,
}

impl Network {
    fn new(layers: Vec<usize>) -> Network {
        let mut weights = Vec::new();
        let mut biases = Vec::new();
        let mut rng = rand::thread_rng();

        for i in 0..layers.len() - 1 {
            weights.push(Array2::from_shape_fn((layers[i], layers[i + 1]), |_| rng.gen()));
            biases.push(Array2::from_shape_fn((1, layers[i + 1]), |_| rng.gen()));
        }

        Network { layers, weights, biases }
    }

    fn forward(&self, input_data: &Array1<f64>) -> Array1<f64> {
        let mut activations = vec![input_data.clone()];
        for (weight, bias) in self.weights.iter().zip(self.biases.iter()) {
            let activation = activations.last().unwrap().dot(weight) + bias;
            activations.push(activation.mapv(|x| x.tanh()));
        }
        activations.last().unwrap().clone()
    }
}

struct DataGenerator {
    size: usize,
    features: usize,
}

impl DataGenerator {
    fn new(size: usize, features: usize) -> DataGenerator {
        DataGenerator { size, features }
    }

    fn generate(&self) -> Array2<f64> {
        let mut rng = rand::thread_rng();
        Array2::from_shape_fn((self.size, self.features), |_| rng.gen())
    }
}

struct Trainer {
    network: Network,
    data_generator: DataGenerator,
}

impl Trainer {
    fn new(network: Network, data_generator: DataGenerator) -> Trainer {
        Trainer { network, data_generator }
    }

    fn train(&self) {
        loop {
            let data = self.data_generator.generate();
            for row in data.rows() {
                self.network.forward(&row);
            }
        }
    }
}

fn main() {
    let layers = vec![784, 128, 64, 10];
    let network = Network::new(layers);
    let data_generator = DataGenerator::new(1000, 784);
    let trainer = Trainer::new(network, data_generator);
    trainer.train();
}