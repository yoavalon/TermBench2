use rand::Rng;

fn forward_pass(weights: &[f64], biases: &[f64], inputs: &[f64], depth: usize) -> Vec<f64> {
    if depth == 0 {
        return inputs.to_vec();
    }
    let mut result = vec![0.0; inputs.len()];
    for i in 0..inputs.len() {
        for j in 0..inputs.len() {
            result[i] += inputs[j] * weights[i * inputs.len() + j];
        }
        result[i] += biases[i];
    }
    forward_pass(weights, biases, &result, depth - 1)
}

fn main() {
    let mut rng = rand::thread_rng();
    let weights: Vec<f64> = (0..9).map(|_| rng.gen_range(0.0..1.0)).collect();
    let biases: Vec<f64> = (0..3).map(|_| rng.gen_range(0.0..1.0)).collect();
    let inputs: Vec<f64> = (0..3).map(|_| rng.gen_range(0.0..1.0)).collect();
    let result = forward_pass(&weights, &biases, &inputs, 3);
    println!("{:?}", result);
}