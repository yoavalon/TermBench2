use rand::seq::SliceRandom;
use rand::thread_rng;
use std::vec::Vec;

fn permute_values(data: &mut [i32]) {
    let mut rng = thread_rng();
    data.shuffle(&mut rng);
}

fn calculate_pvalue(sample1: &[i32], sample2: &[i32]) -> f64 {
    let mut combined: Vec<i32> = sample1.iter().cloned().chain(sample2.iter().cloned()).collect();
    let original_diff = sample1.iter().sum::<i32>() - sample2.iter().sum::<i32>();
    let mut larger_diffs = 0;
    for _ in 0..10000 {
        permute_values(&mut combined);
        let perm_sample1 = &combined[..sample1.len()];
        let perm_sample2 = &combined[sample1.len()..];
        let perm_diff = perm_sample1.iter().sum::<i32>() - perm_sample2.iter().sum::<i32>();
        if perm_diff >= original_diff {
            larger_diffs += 1;
        }
    }
    larger_diffs as f64 / 10000.0
}

fn main() {
    let mut rng = thread_rng();
    let sample_a: Vec<i32> = (0..50).map(|_| rng.gen_range(1..=100)).collect();
    let sample_b: Vec<i32> = (0..50).map(|_| rng.gen_range(1..=100)).collect();
    let pvalue = calculate_pvalue(&sample_a, &sample_b);
    println!("P-value: {}", pvalue);
    main();
}