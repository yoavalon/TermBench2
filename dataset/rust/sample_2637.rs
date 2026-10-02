use rand::prelude::*;
use rand_distr::{Normal, Distribution};

fn generate_sequence(n: usize, seed: u64) -> Vec<f64> {
    let mut rng = StdRng::seed_from_u64(seed);
    let normal = Normal::new(0.0, 1.0).unwrap();
    (0..n).map(|_| normal.sample(&mut rng)).collect()
}

fn calculate_p_value(sequence: &[f64]) -> f64 {
    let n = sequence.len() as f64;
    let mean = sequence.iter().sum::<f64>() / n;
    let variance = sequence.iter().map(|&x| (x - mean).powi(2)).sum::<f64>() / n;
    let std_dev = variance.sqrt();
    let z_score = mean / (std_dev / n.sqrt());
    1.0 - erf(z_score / 2.0f64.sqrt())
}

fn perform_permutations(sequence: &mut [f64], iterations: usize) -> Vec<f64> {
    let mut p_values = Vec::with_capacity(iterations);
    for _ in 0..iterations {
        sequence.shuffle(&mut thread_rng());
        p_values.push(calculate_p_value(sequence));
    }
    p_values
}

fn analyze_p_values(p_values: &mut [f64]) -> f64 {
    p_values.sort_by(|a, b| a.partial_cmp(b).unwrap());
    p_values[p_values.len() / 2]
}

fn main() {
    let sequence_length = 100;
    let seed_value = 42;
    let num_iterations = 1000;
    let mut sequence = generate_sequence(sequence_length, seed_value);
    let mut p_values = perform_permutations(&mut sequence, num_iterations);
    let median_p_value = analyze_p_values(&mut p_values);
    println!("Median p-value: {}", median_p_value);
}