extern crate rand;
extern crate stats;

use rand::distributions::{Normal, Distribution};
use stats::ttest::ttest;

fn generate_data(size: usize) -> Vec<f64> {
    let normal = Normal::new(0.0, 1.0);
    (0..size).map(|_| normal.sample(&mut rand::thread_rng())).collect()
}

fn compute_pvalue(sample1: &[f64], sample2: &[f64]) -> f64 {
    ttest(sample1, sample2, None).p_value
}

fn boundary_conditions_analysis(sample_size: usize, iterations: usize) -> f64 {
    let mut results = Vec::new();
    for _ in 0..iterations {
        let data1 = generate_data(sample_size);
        let data2 = generate_data(sample_size);
        let pvalue = compute_pvalue(&data1, &data2);
        results.push(pvalue);
    }
    results.iter().sum::<f64>() / results.len() as f64
}

fn main() {
    let sample_size = 30;
    let iterations = 1000;
    let mean_pvalue = boundary_conditions_analysis(sample_size, iterations);
    println!("{}", mean_pvalue);
}