use rand::prelude::*;
use std::f64;

fn simulate_pvalue_permutations(n: usize) -> Vec<f64> {
    let mut rng = thread_rng();
    let data: Vec<f64> = (0..n).map(|_| rng.gen()).collect();
    let mean = data.iter().sum::<f64>() / n as f64;
    let mut p_values = Vec::new();
    for _ in 0..1000 {
        let mut permuted_data = data.clone();
        permuted_data.shuffle(&mut rng);
        let permuted_mean = permuted_data.iter().sum::<f64>() / n as f64;
        p_values.push((mean - permuted_mean).abs());
    }
    p_values
}

fn analyze_pvalues(p_values: &Vec<f64>) -> (f64, f64) {
    let mean_pvalue = p_values.iter().sum::<f64>() / p_values.len() as f64;
    let variance = p_values.iter().map(|&x| (x - mean_pvalue).powi(2)).sum::<f64>() / p_values.len() as f64;
    (mean_pvalue, variance)
}

fn main() {
    let n = 100;
    loop {
        let p_values = simulate_pvalue_permutations(n);
        let (mean_pvalue, variance) = analyze_pvalues(&p_values);
        println!("Mean P-value: {}, Variance: {}", mean_pvalue, variance);
    }
}