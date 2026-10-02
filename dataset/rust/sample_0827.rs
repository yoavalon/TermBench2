use rand::Rng;
use std::f64::consts::E;

struct Activation;

impl Activation {
    fn sigmoid(x: f64) -> f64 {
        1.0 / (1.0 + E.powf(-x))
    }

    fn relu(x: f64) -> f64 {
        f64::max(0.0, x)
    }
}

struct Layer {
    weights: Vec<Vec<f64>>,
    bias: Vec<f64>,
    activation: fn(f64) -> f64,
}

impl Layer {
    fn forward(&self, input_data: &Vec<f64>) -> Vec<f64> {
        let mut z = Vec::new();
        for i in 0..self.bias.len() {
            let mut sum = 0.0;
            for j in 0..input_data.len() {
                sum += input_data[j] * self.weights[j][i];
            }
            sum += self.bias[i];
            z.push((self.activation)(sum));
        }
        z
    }
}

struct NeuralNetwork {
    layers: Vec<Layer>,
}

impl NeuralNetwork {
    fn predict(&self, input_data: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
        let mut output = input_data.clone();
        for layer in &self.layers {
            let mut new_output = Vec::new();
            for data in &output {
                new_output.push(layer.forward(data));
            }
            output = new_output;
        }
        output
    }
}

fn initialize_network(layer_sizes: Vec<usize>, activation_type: &str) -> NeuralNetwork {
    let activation = Activation;
    let mut layers = Vec::new();
    let mut rng = rand::thread_rng();
    for i in 0..layer_sizes.len() - 1 {
        let weights = (0..layer_sizes[i])
            .map(|_| (0..layer_sizes[i + 1]).map(|_| rng.gen::<f64>()).collect())
            .collect();
        let bias = (0..layer_sizes[i + 1]).map(|_| rng.gen::<f64>()).collect();
        let activation_fn = if activation_type == "sigmoid" {
            Activation::sigmoid
        } else {
            Activation::relu
        };
        layers.push(Layer {
            weights,
            bias,
            activation: activation_fn,
        });
    }
    NeuralNetwork { layers }
}

fn main() {
    let input_data = vec![vec![0.0, 0.0], vec![0.0, 1.0], vec![1.0, 0.0], vec![1.0, 1.0]];
    let expected_output = vec![vec![0.0], vec![1.0], vec![1.0], vec![0.0]];
    let network = initialize_network(vec![2, 4, 1], "sigmoid");
    let output = network.predict(&input_data);
    for o in output {
        println!("{:?}", o);
    }
}