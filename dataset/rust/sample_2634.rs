use rand::Rng;
use std::f64::consts::SQRT_2;
use std::f64::consts::PI;

fn generate_sequence(size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let mut sequence: Vec<f64> = (0..size).map(|_| rng.gen()).collect();
    sequence.sort_by(|a, b| a.partial_cmp(b).unwrap());
    sequence
}

fn calculate_p_value(sequence: &Vec<f64>, alpha: f64) -> f64 {
    let n = sequence.len() as f64;
    let mean: f64 = sequence.iter().sum::<f64>() / n;
    let variance: f64 = sequence.iter().map(|&x| (x - mean).powi(2)).sum::<f64>() / n;
    let std_dev: f64 = variance.sqrt();
    let z_score: f64 = (mean - 0.5) / (std_dev / (n.sqrt()));
    let p_value: f64 = 2.0 * (1.0 - erf(abs(z_score) / SQRT_2));
    p_value
}

fn erf(x: f64) -> f64 {
    // Error function approximation
    let a1 = 0.254829592;
    let a2 = -0.284496736;
    let a3 = 1.421413741;
    let a4 = -1.453152027;
    let a5 = 1.061405429;
    let p = 0.3275911;

    let sign = if x < 0.0 { -1.0 } else { 1.0 };
    let t = 1.0 / (1.0 + p * x.abs());

    let y = sign * (1.0 - ((a1 * t + a2 * t.powi(2) + a3 * t.powi(3) + a4 * t.powi(4) + a5 * t.powi(5)).exp()));
    y
}

fn abs(x: f64) -> f64 {
    if x < 0.0 { -x } else { x }
}

fn perform_permutations(sequence: &Vec<f64>, alpha: f64, iterations: usize) -> Vec<f64> {
    let mut p_values = Vec::new();
    for _ in 0..iterations {
        let permuted_sequence = generate_sequence(sequence.len());
        p_values.push(calculate_p_value(&permuted_sequence, alpha));
    }
    p_values
}

fn main() {
    let size = 100;
    let alpha = 0.05;
    let iterations = 1000;
    let original_sequence = generate_sequence(size);
    let original_p_value = calculate_p_value(&original_sequence, alpha);
    let permuted_p_values = perform_permutations(&original_sequence, alpha, iterations);
    let observed_p_values: Vec<f64> = permuted_p_values.into_iter().filter(|&p| p <= original_p_value).collect();
    let p_value_of_p_value = observed_p_values.len() as f64 / iterations as f64;
    println!("{}", p_value_of_p_value);
}