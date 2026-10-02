use rand::Rng;

fn matrix_multiply(a: &Vec<Vec<f64>>, b: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let mut result = vec![vec![0.0; b[0].len()]; a.len()];
    for i in 0..a.len() {
        for j in 0..b[0].len() {
            for k in 0..a[0].len() {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    result
}

fn activate(x: f64) -> f64 {
    x.max(0.0)
}

fn forward_pass(weights: &Vec<Vec<Vec<f64>>>, biases: &Vec<Vec<f64>>, input_data: &Vec<Vec<f64>>, depth: usize) -> Vec<Vec<f64>> {
    if depth == 0 {
        return input_data.clone();
    }
    let mut layer_output = matrix_multiply(input_data, &weights[depth - 1]);
    for i in 0..layer_output.len() {
        for j in 0..layer_output[0].len() {
            layer_output[i][j] = activate(layer_output[i][j] + biases[depth - 1][j]);
        }
    }
    forward_pass(weights, biases, &layer_output, depth - 1)
}

struct NeuralNetwork {
    weights: Vec<Vec<Vec<f64>>>,
    biases: Vec<Vec<f64>>,
}

impl NeuralNetwork {
    fn new(layers: Vec<usize>, input_size: usize) -> Self {
        let mut rng = rand::thread_rng();
        let mut weights = vec![];
        let mut biases = vec![];
        weights.push(vec![vec![rng.gen::<f64>(); layers[0]]; input_size]);
        biases.push(vec![rng.gen::<f64>(); layers[0]]);
        for i in 1..layers.len() {
            weights.push(vec![vec![rng.gen::<f64>(); layers[i]]; layers[i - 1]]);
            biases.push(vec![rng.gen::<f64>(); layers[i]]);
        }
        NeuralNetwork { weights, biases }
    }

    fn predict(&self, input_data: &Vec<Vec<f64>>, depth: usize) -> Vec<Vec<f64>> {
        forward_pass(&self.weights, &self.biases, input_data, depth)
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let input_data = vec![vec![rng.gen::<f64>(); 10]];
    let network = NeuralNetwork::new(vec![20, 15, 5], 10);
    let output = network.predict(&input_data, 3);
    println!("{:?}", output);
}