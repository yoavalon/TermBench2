use rand::Rng;
use std::f64::consts::E;

fn sigmoid(x: f64) -> f64 {
    1.0 / (1.0 + E.powf(-x))
}

fn forward_pass(weights: &[Vec<Vec<f64>>], biases: &[Vec<f64>], inputs: &Vec<f64>) -> Vec<f64> {
    let mut inputs = inputs.clone();
    for (w, b) in weights.iter().zip(biases.iter()) {
        let mut new_inputs = Vec::new();
        for i in 0..w.len() {
            let mut sum = 0.0;
            for j in 0..inputs.len() {
                sum += w[i][j] * inputs[j];
            }
            sum += b[i];
            new_inputs.push(sigmoid(sum));
        }
        inputs = new_inputs;
    }
    inputs
}

fn main() {
    let mut rng = rand::thread_rng();
    let layers = 3;
    let input_size = 5;
    let output_size = 1;
    let hidden_size = 4;
    let mut weights = Vec::new();
    let mut biases = Vec::new();

    for i in 0..layers {
        if i == 0 {
            weights.push((0..hidden_size).map(|_| (0..input_size).map(|_| rng.gen::<f64>()).collect()).collect());
            biases.push((0..hidden_size).map(|_| rng.gen::<f64>()).collect());
        } else {
            weights.push((0..output_size).map(|_| (0..hidden_size).map(|_| rng.gen::<f64>()).collect()).collect());
            biases.push((0..output_size).map(|_| rng.gen::<f64>()).collect());
        }
    }

    let inputs: Vec<f64> = (0..input_size).map(|_| rng.gen::<f64>()).collect();
    let result = forward_pass(&weights, &biases, &inputs);
    println!("{:?}", result);
}