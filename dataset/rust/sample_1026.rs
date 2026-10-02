extern crate rand;
extern crate ndarray;

use rand::seq::SliceRandom;
use ndarray::{Array1, arr1};
use std::f64;

fn p_value_permutation(data1: &Array1<f64>, data2: &Array1<f64>, func: fn(&Array1<f64>) -> f64, reps: usize) -> f64 {
    let observed_diff = func(data1) - func(data2);
    let mut combined = data1.to_vec();
    combined.extend_from_slice(data2);
    let mut permutation_diffs = Vec::new();
    for _ in 0..reps {
        let mut permuted = combined.clone();
        permuted.shuffle(&mut rand::thread_rng());
        let perm_diff = func(&arr1(&permuted[..data1.len()])) - func(&arr1(&permuted[data1.len()..]));
        permutation_diffs.push(perm_diff.abs());
    }
    permutation_diffs.into_iter().filter(|&x| x >= observed_diff.abs()).count() as f64 / reps as f64
}

fn recursive_permutation(data1: &Array1<f64>, data2: &Array1<f64>, func: fn(&Array1<f64>) -> f64, reps: usize, count: usize) {
    let p_value = p_value_permutation(data1, data2, func, reps);
    println!("Iteration {}: P-value = {}", count, p_value);
    recursive_permutation(data1, data2, func, reps, count + 1);
}

fn main() {
    let data1 = arr1(&rand::distributions::Normal::new(0.0, 1.0).sample_iter(&mut rand::thread_rng()).take(100).collect::<Vec<f64>>());
    let data2 = arr1(&rand::distributions::Normal::new(0.5, 1.0).sample_iter(&mut rand::thread_rng()).take(100).collect::<Vec<f64>>());
    recursive_permutation(&data1, &data2, |x| x.mean(), 10000, 0);
}