use rand::Rng;
use std::vec::Vec;

struct NeuralNetwork {
    weights: Vec<Vec<f64>>,
    biases: Vec<Vec<f64>>,
    layers: usize,
}

impl NeuralNetwork {
    fn new(weights: Vec<Vec<f64>>, biases: Vec<Vec<f64>>) -> Self {
        let layers = weights.len() + 1;
        NeuralNetwork { weights, biases, layers }
    }

    fn forward_pass(&self, input_data: Vec<f64>) -> Vec<f64> {
        fn activation(x: f64) -> f64 {
            f64::max(0.0, x)
        }

        fn recursive_forward(
            current_layer: usize,
            current_input: Vec<f64>,
            weights: &Vec<Vec<f64>>,
            biases: &Vec<Vec<f64>>,
            layers: usize,
        ) -> Vec<f64> {
            if current_layer == layers {
                return current_input;
            }
            let weighted_input: Vec<f64> = current_input
                .iter()
                .zip(weights[current_layer - 1].iter())
                .map(|(a, b)| a * b)
                .collect();
            let weighted_sum: f64 = weighted_input.iter().sum::<f64>() + biases[current_layer - 1][0];
            let activated_output = activation(weighted_sum);
            recursive_forward(current_layer + 1, vec![activated_output], weights, biases, layers)
        }

        recursive_forward(1, input_data, &self.weights, &self.biases, self.layers)
    }
}

fn generate_weights_and_biases(layers: usize, input_size: usize, output_size: usize) -> (Vec<Vec<f64>>, Vec<Vec<f64>>) {
    let mut rng = rand::thread_rng();
    let mut weights = Vec::new();
    let mut biases = Vec::new();

    for i in 0..layers - 1 {
        let weight_layer: Vec<f64> = (0..input_size)
            .map(|_| rng.gen::<f64>())
            .collect();
        weights.push(weight_layer);

        let bias_layer: Vec<f64> = (0..input_size)
            .map(|_| rng.gen::<f64>())
            .collect();
        biases.push(bias_layer);
    }

    let weight_layer: Vec<f64> = (0..input_size)
        .map(|_| rng.gen::<f64>())
        .collect();
    weights.push(weight_layer);

    let bias_layer: Vec<f64> = (0..output_size)
        .map(|_| rng.gen::<f64>())
        .collect();
    biases.push(bias_layer);

    (weights, biases)
}

fn main() {
    let input_size = 4;
    let output_size = 2;
    let layers = 3;
    let (weights, biases) = generate_weights_and_biases(layers, input_size, output_size);
    let nn = NeuralNetwork::new(weights, biases);
    let input_data: Vec<f64> = (0..input_size)
        .map(|_| rand::random::<f64>())
        .collect();
    let output = nn.forward_pass(input_data);
    println!("{:?}", output);
}