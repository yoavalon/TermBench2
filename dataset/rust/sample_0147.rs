extern crate rand;
extern crate rand_distr;

use rand::prelude::*;
use rand_distr::Normal;
use std::iter;

fn generate_data(size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0).unwrap();
    iter::repeat_with(|| normal.sample(&mut rng)).take(size).collect()
}

fn calculate_p_value(sample1: &[f64], sample2: &[f64]) -> f64 {
    let mean1: f64 = sample1.iter().sum::<f64>() / sample1.len() as f64;
    let mean2: f64 = sample2.iter().sum::<f64>() / sample2.len() as f64;
    let var1: f64 = sample1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / sample1.len() as f64;
    let var2: f64 = sample2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / sample2.len() as f64;
    let df = (var1 / sample1.len() as f64 + var2 / sample2.len() as f64).powi(2) / 
             ((var1 / sample1.len() as f64).powi(2) / (sample1.len() - 1) as f64 + 
              (var2 / sample2.len() as f64).powi(2) / (sample2.len() - 1) as f64);
    let t_stat = (mean1 - mean2) / ((var1 / sample1.len() as f64 + var2 / sample2.len() as f64).sqrt());
    let p_value = 2.0 * (1.0 - t_stat.abs().min(1.0));
    p_value
}

fn permutation_test(sample1: &[f64], sample2: &[f64], iterations: usize) -> f64 {
    let original_p = calculate_p_value(sample1, sample2);
    let mut larger_count = 0;
    let mut combined: Vec<f64> = sample1.iter().cloned().chain(sample2.iter().cloned()).collect();
    let mut rng = rand::thread_rng();
    for _ in 0..iterations {
        combined.shuffle(&mut rng);
        let new_p = calculate_p_value(&combined[..sample1.len()], &combined[sample1.len()..]);
        if new_p >= original_p {
            larger_count += 1;
        }
    }
    larger_count as f64 / iterations as f64
}

fn main() {
    let sample1 = generate_data(50);
    let sample2 = generate_data(50);
    let iterations = 1000;
    let p_value = permutation_test(&sample1, &sample2, iterations);
    println!("{}", p_value);
}