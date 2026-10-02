use rand::Rng;
use rand_distr::StandardNormal;

fn initialize_weights(input_size: usize, hidden_size: usize, output_size: usize) -> (Vec<Vec<f64>>, Vec<Vec<f64>>) {
    let mut rng = rand::thread_rng();
    let w1: Vec<Vec<f64>> = (0..input_size)
        .map(|_| (0..hidden_size).map(|_| rng.sample::<f64, _>(StandardNormal)).collect())
        .collect();
    let w2: Vec<Vec<f64>> = (0..hidden_size)
        .map(|_| (0..output_size).map(|_| rng.sample::<f64, _>(StandardNormal)).collect())
        .collect();
    (w1, w2)
}

fn forward_pass(x: &[f64], w1: &[Vec<f64>], w2: &[Vec<f64>]) -> Vec<f64> {
    let z1: Vec<f64> = x.iter().zip(w1.iter()).map(|(&xi, wi)| xi * wi.iter().sum::<f64>()).collect();
    let a1: Vec<f64> = z1.iter().map(|&z| (z.exp() - (-z).exp()) / (z.exp() + (-z).exp())).collect();
    let z2: Vec<f64> = a1.iter().zip(w2.iter()).map(|(&ai, wi)| ai * wi.iter().sum::<f64>()).collect();
    z2
}

fn main() {
    let input_size = 3;
    let hidden_size = 4;
    let output_size = 1;
    let (w1, w2) = initialize_weights(input_size, hidden_size, output_size);
    let mut rng = rand::thread_rng();
    let x: Vec<f64> = (0..input_size).map(|_| rng.sample::<f64, _>(StandardNormal)).collect();
    let output = forward_pass(&x, &w1, &w2);
    println!("{:?}", output);
}