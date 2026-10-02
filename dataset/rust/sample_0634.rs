use rand::seq::SliceRandom;
use rand::thread_rng;
use std::vec::Vec;

fn permute_pvalues(data: &[f64], n: usize) -> Vec<f64> {
    if n == 0 {
        vec![0.0]
    } else {
        let mut rng = thread_rng();
        let mut permuted = data.to_vec();
        permuted.shuffle(&mut rng);
        let mean = permuted.iter().sum::<f64>() / permuted.len() as f64;
        let mut results = permute_pvalues(data, n - 1);
        results.push(mean);
        results
    }
}

fn main() {
    let data = vec![0.05, 0.03, 0.07, 0.1];
    let n = 1000;
    let results = permute_pvalues(&data, n);
    println!("{}", results[n]);
}