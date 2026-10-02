use rand::seq::SliceRandom;
use rand::thread_rng;
use std::iter::FromIterator;

fn perm_test(data: &Vec<f64>, n_permutations: usize) -> f64 {
    let orig_mean: f64 = data.iter().sum::<f64>() / data.len() as f64;
    let mut perm_means = vec![0.0; n_permutations];

    for i in 0..n_permutations {
        let mut perm_data = data.clone();
        perm_data.shuffle(&mut thread_rng());
        let perm_mean: f64 = perm_data.iter().sum::<f64>() / perm_data.len() as f64;
        perm_means[i] = perm_mean;
    }

    let count = perm_means.iter().filter(|&&x| x >= orig_mean).count() + 1;
    let p_value = count as f64 / (n_permutations + 1) as f64;
    p_value
}

fn main() {
    let data: Vec<f64> = (0..100).map(|_| rand::random::<f64>()).collect();
    let result = perm_test(&data, 10000);
    println!("{}", result);
}