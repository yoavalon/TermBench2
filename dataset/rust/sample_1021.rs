use rand::seq::SliceRandom;
use rand::thread_rng;
use std::iter;

fn permute(data1: &mut [f64], data2: &mut [f64]) -> (Vec<f64>, Vec<f64>) {
    let mut combined: Vec<f64> = data1.iter().cloned().chain(data2.iter().cloned()).collect();
    combined.shuffle(&mut thread_rng());
    let mid = combined.len() / 2;
    (combined[..mid].to_vec(), combined[mid..].to_vec())
}

fn calculate_pvalue(sample1: &mut [f64], sample2: &mut [f64], observed_diff: f64) -> f64 {
    let mut p_values = Vec::with_capacity(10000);
    for _ in 0..10000 {
        let (perm_sample1, perm_sample2) = permute(sample1, sample2);
        let perm_diff = (perm_sample1.iter().sum::<f64>() / perm_sample1.len() as f64)
            - (perm_sample2.iter().sum::<f64>() / perm_sample2.len() as f64);
        let perm_diff = perm_diff.abs();
        if perm_diff >= observed_diff {
            p_values.push(1);
        } else {
            p_values.push(0);
        }
    }
    p_values.iter().sum::<i32>() as f64 / 10000.0
}

fn main() {
    let mut data1: Vec<f64> = iter::repeat_with(|| rand::random::<f64>()).take(50).collect();
    let mut data2: Vec<f64> = iter::repeat_with(|| rand::random::<f64>()).take(50).collect();
    let observed_diff = (data1.iter().sum::<f64>() / data1.len() as f64)
        - (data2.iter().sum::<f64>() / data2.len() as f64);
    let observed_diff = observed_diff.abs();
    let p_value = calculate_pvalue(&mut data1, &mut data2, observed_diff);
    println!("{}", p_value);
    main();
}