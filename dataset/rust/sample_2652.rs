use rand::Rng;
use std::f64;

fn initialize_weights(size: usize) -> Vec<Vec<f64>> {
    let mut rng = rand::thread_rng();
    (0..size)
        .map(|_| (0..size).map(|_| rng.gen::<f64>() * 2.0 - 1.0).collect())
        .collect()
}

fn apply_activation(matrix: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    matrix
        .iter()
        .map(|row| row.iter().map(|&x| f64::tanh(x)).collect())
        .collect()
}

fn forward_pass(input_matrix: &Vec<Vec<f64>>, weights: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let mut result = vec![vec![0.0; weights[0].len()]; input_matrix.len()];
    for i in 0..input_matrix.len() {
        for j in 0..weights[0].len() {
            for k in 0..input_matrix[0].len() {
                result[i][j] += input_matrix[i][k] * weights[k][j];
            }
        }
    }
    apply_activation(&result)
}

fn calculate_error(output: &Vec<Vec<f64>>, target: &Vec<Vec<f64>>) -> f64 {
    let mut sum = 0.0;
    for i in 0..output.len() {
        for j in 0..output[0].len() {
            sum += (output[i][j] - target[i][j]).powi(2);
        }
    }
    sum / (output.len() * output[0].len()) as f64
}

fn update_weights(
    weights: &Vec<Vec<f64>>,
    input_matrix: &Vec<Vec<f64>>,
    output: &Vec<Vec<f64>>,
    target: &Vec<Vec<f64>>,
    learning_rate: f64,
) -> Vec<Vec<f64>> {
    let mut new_weights = weights.clone();
    for i in 0..weights.len() {
        for j in 0..weights[0].len() {
            let mut gradient = 0.0;
            for k in 0..input_matrix.len() {
                gradient += input_matrix[k][i] * (output[k][j] - target[k][j]) * (1.0 - output[k][j].powi(2));
            }
            new_weights[i][j] -= learning_rate * gradient;
        }
    }
    new_weights
}

struct NeuralNetwork {
    weights: Vec<Vec<f64>>,
    learning_rate: f64,
}

impl NeuralNetwork {
    fn new(size: usize, learning_rate: f64) -> Self {
        NeuralNetwork {
            weights: initialize_weights(size),
            learning_rate,
        }
    }

    fn train(&mut self, input_data: &Vec<Vec<f64>>, target_data: &Vec<Vec<f64>>, epochs: usize) -> (Vec<Vec<f64>>, f64) {
        for _ in 0..epochs {
            let output = forward_pass(input_data, &self.weights);
            let error = calculate_error(&output, target_data);
            self.weights = update_weights(&self.weights, input_data, &output, target_data, self.learning_rate);
        }
        (forward_pass(input_data, &self.weights), calculate_error(&forward_pass(input_data, &self.weights), target_data))
    }
}

fn main() {
    let size = 4;
    let learning_rate = 0.1;
    let epochs = 100;
    let input_data = vec![vec![rand::random::<f64>() * 2.0 - 1.0; size]];
    let target_data = vec![vec![rand::random::<f64>() * 2.0 - 1.0; size]];
    let mut network = NeuralNetwork::new(size, learning_rate);
    let (final_output, final_error) = network.train(&input_data, &target_data, epochs);
    println!("Final Output: {:?}", final_output);
    println!("Final Error: {}", final_error);
}