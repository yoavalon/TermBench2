use rand::Rng;
use std::f64::consts::E;

fn sigmoid(x: f64) -> f64 {
    1.0 / (1.0 + E.powf(-x))
}

fn forward_pass(weights: &[f64], bias: &[f64], input_data: &[f64]) -> Vec<f64> {
    let mut layer1 = Vec::new();
    for i in 0..bias.len() {
        let mut sum = bias[i];
        for j in 0..weights.len() / bias.len() {
            sum += weights[i * (weights.len() / bias.len()) + j] * input_data[j];
        }
        layer1.push(sigmoid(sum));
    }
    layer1
}

fn main() {
    let mut rng = rand::thread_rng();
    rng.seed([0; 32]);
    let weights: Vec<f64> = (0..12).map(|_| rng.gen()).collect();
    let bias: Vec<f64> = (0..4).map(|_| rng.gen()).collect();
    let input_data: Vec<f64> = (0..12).map(|_| rng.gen()).collect();
    let result = forward_pass(&weights, &bias, &input_data);
    for &v in &result {
        println!("{}", v);
    }
}