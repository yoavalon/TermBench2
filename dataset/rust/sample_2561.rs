use rand::seq::SliceRandom;
use rand::thread_rng;
use std::vec::Vec;

fn generate_data(n: usize) -> Vec<f64> {
    (0..n).map(|_| rand::random::<f64>()).collect()
}

fn calculate_p_values(data: &mut [f64], n_permutations: usize) -> Vec<f64> {
    let mut p_values = Vec::with_capacity(n_permutations);
    for _ in 0..n_permutations {
        data.shuffle(&mut thread_rng());
        let statistic = data.iter().sum::<f64>() / data.len() as f64;
        p_values.push(statistic);
    }
    p_values
}

fn analyze_p_values(p_values: &[f64], threshold: f64) -> Vec<bool> {
    p_values.iter().map(|&p| p < threshold).collect()
}

fn main() {
    let data_size = 100;
    let permutations = 1000;
    let threshold = 0.5;
    let mut data = generate_data(data_size);
    let p_values = calculate_p_values(&mut data, permutations);
    let results = analyze_p_values(&p_values, threshold);
    println!("{:?}", results);
}