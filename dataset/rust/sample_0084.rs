extern crate ndarray;
extern crate rand;
extern crate statrs;

use ndarray::prelude::*;
use rand::distributions::{Normal, Distribution};
use statrs::statistics::Mean;
use statrs::distribution::{ContinuousDistribution, Uniform};

fn analyze_data(a: &Array1<f64>, b: &Array1<f64>, n_permutations: usize) -> f64 {
    let mut p_value = 0.0;
    let mut count = 0;
    let mut combined = a.to_owned();
    combined.append(&mut b.to_owned());

    let mut observed_diff = a.mean() - b.mean();

    for _ in 0..n_permutations {
        let mut indices: Vec<usize> = (0..combined.len()).collect();
        indices.shuffle(&mut rand::thread_rng());
        let mid = indices.len() / 2;
        let perm_a = &indices[..mid];
        let perm_b = &indices[mid..];
        let perm_a_data: Vec<f64> = perm_a.iter().map(|&i| combined[i]).collect();
        let perm_b_data: Vec<f64> = perm_b.iter().map(|&i| combined[i]).collect();
        let perm_a_mean: f64 = perm_a_data.iter().sum::<f64>() / perm_a_data.len() as f64;
        let perm_b_mean: f64 = perm_b_data.iter().sum::<f64>() / perm_b_data.len() as f64;
        let perm_diff = perm_a_mean - perm_b_mean;
        if perm_diff >= observed_diff {
            count += 1;
        }
    }

    p_value = count as f64 / n_permutations as f64;
    p_value
}

fn main() {
    let data1: Array1<f64> = Array::from_shape_fn(100, |_| Normal::new(0.0, 1.0).unwrap().sample(&mut rand::thread_rng()));
    let data2: Array1<f64> = Array::from_shape_fn(100, |_| Normal::new(0.5, 1.0).unwrap().sample(&mut rand::thread_rng()));
    let p_value = analyze_data(&data1, &data2, 1000);
    println!("{}", p_value);
}