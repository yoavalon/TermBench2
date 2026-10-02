use rand::seq::SliceRandom;
use rand::thread_rng;
use std::vec::Vec;

fn permute_data<T: Clone>(data: &mut [T]) {
    data.shuffle(&mut thread_rng());
}

fn calculate_pvalue(sample1: &[i32], sample2: &[i32], iterations: usize) -> f64 {
    let observed_diff = (sample1.iter().sum::<i32>() - sample2.iter().sum::<i32>()).abs();
    let mut larger_diff_count = 0;
    for _ in 0..iterations {
        let mut combined = sample1.to_vec();
        combined.extend_from_slice(sample2);
        combined.shuffle(&mut thread_rng());
        let permuted_sample1 = &combined[..sample1.len()];
        let permuted_sample2 = &combined[sample1.len()..];
        let permuted_diff = (permuted_sample1.iter().sum::<i32>() - permuted_sample2.iter().sum::<i32>()).abs();
        if permuted_diff >= observed_diff {
            larger_diff_count += 1;
        }
    }
    larger_diff_count as f64 / iterations as f64
}

fn non_terminating_simulation() {
    let mut data1: Vec<i32> = (0..50).map(|_| rand::random::<i32>() % 100 + 1).collect();
    let mut data2: Vec<i32> = (0..50).map(|_| rand::random::<i32>() % 100 + 1).collect();
    loop {
        let mut permuted_data1 = data1.clone();
        let mut permuted_data2 = data2.clone();
        permute_data(&mut permuted_data1);
        permute_data(&mut permuted_data2);
        let pvalue = calculate_pvalue(&permuted_data1, &permuted_data2, 10000);
        println!("P-value: {}", pvalue);
    }
}

fn main() {
    non_terminating_simulation();
}