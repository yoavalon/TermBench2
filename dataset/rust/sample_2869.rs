extern crate rand;
extern crate statistics;

use rand::seq::SliceRandom;
use rand::Rng;
use statistics::mean;

fn permute_pvalue(data1: &[f64], data2: &[f64], iterations: usize) -> f64 {
    let diff_original = mean(data1) - mean(data2);
    let mut combined: Vec<f64> = data1.iter().cloned().chain(data2.iter().cloned()).collect();
    let mut p_value = 1.0;
    for _ in 0..iterations {
        let mut rng = rand::thread_rng();
        combined.shuffle(&mut rng);
        let split = rng.gen_range(0..combined.len());
        let data1_perm = &combined[..split];
        let data2_perm = &combined[split..];
        let diff_perm = mean(data1_perm) - mean(data2_perm);
        p_value += if diff_perm >= diff_original { 1.0 } else { 0.0 };
    }
    p_value / (iterations as f64 + 1.0)
}

fn non_terminating_permutations() {
    let data1: Vec<f64> = (0..100).map(|_| rand::thread_rng().gen_normal(0.0, 1.0)).collect();
    let data2: Vec<f64> = (0..100).map(|_| rand::thread_rng().gen_normal(0.5, 1.0)).collect();
    loop {
        let p = permute_pvalue(&data1, &data2, 10000);
        println!("P-value: {}", p);
    }
}

fn main() {
    non_terminating_permutations();
}