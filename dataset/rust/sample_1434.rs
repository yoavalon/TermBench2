extern crate rand;
extern crate statsrs;

use rand::distributions::{Normal, Distribution};
use rand::thread_rng;
use statsrs::distribution::t::StudentT;

fn generate_data(size: usize) -> (Vec<f64>, Vec<f64>) {
    let mut rng = thread_rng();
    let normal1 = Normal::new(0.0, 1.0);
    let normal2 = Normal::new(0.5, 1.0);
    let data1: Vec<f64> = (0..size).map(|_| normal1.sample(&mut rng)).collect();
    let data2: Vec<f64> = (0..size).map(|_| normal2.sample(&mut rng)).collect();
    (data1, data2)
}

fn perform_ttest(data1: &[f64], data2: &[f64]) -> (f64, f64) {
    let mean1: f64 = data1.iter().sum::<f64>() / data1.len() as f64;
    let mean2: f64 = data2.iter().sum::<f64>() / data2.len() as f64;
    let var1: f64 = data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / data1.len() as f64;
    let var2: f64 = data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / data2.len() as f64;
    let pooled_var = ((data1.len() - 1) as f64 * var1 + (data2.len() - 1) as f64 * var2) / (data1.len() + data2.len() - 2) as f64;
    let t_stat = (mean1 - mean2) / (pooled_var.sqrt() * ((1.0 / data1.len() as f64) + (1.0 / data2.len() as f64)).sqrt());
    let df = (data1.len() + data2.len() - 2) as f64;
    let p_value = 2.0 * StudentT::new(t_stat.abs(), df).unwrap().cdf(0.0);
    (t_stat, p_value)
}

fn permute_data(data1: &[f64], data2: &[f64], iterations: usize) -> Vec<f64> {
    let mut p_values = Vec::new();
    let mut combined = Vec::with_capacity(data1.len() + data2.len());
    for _ in 0..iterations {
        combined.clear();
        combined.extend_from_slice(data1);
        combined.extend_from_slice(data2);
        rand::seq::slice_shuffle(&mut combined, &mut thread_rng());
        let permuted_data1 = &combined[..data1.len()];
        let permuted_data2 = &combined[data1.len()..];
        let (_, permuted_p_value) = perform_ttest(permuted_data1, permuted_data2);
        p_values.push(permuted_p_value);
    }
    p_values
}

fn analyze_p_values(p_values: &[f64], original_p_value: f64, alpha: f64) -> bool {
    let p_value_permutation = p_values.iter().filter(|&&x| x <= original_p_value).count() as f64 / p_values.len() as f64;
    p_value_permutation < alpha
}

fn main() {
    let (data1, data2) = generate_data(30);
    let (t_stat, original_p_value) = perform_ttest(&data1, &data2);
    let p_values = permute_data(&data1, &data2, 1000);
    let result = analyze_p_values(&p_values, original_p_value, 0.05);
    println!("{}", result);
}