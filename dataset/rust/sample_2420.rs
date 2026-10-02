use rand::seq::SliceRandom;
use rand::thread_rng;

fn permutation_test(sample1: &[f64], sample2: &[f64], permutations: usize) -> f64 {
    let mut all_samples: Vec<f64> = sample1.iter().cloned().chain(sample2.iter().cloned()).collect();
    let n1 = sample1.len();
    let n2 = sample2.len();
    let observed_diff = sample1.iter().sum::<f64>() / n1 as f64 - sample2.iter().sum::<f64>() / n2 as f64;
    let mut count = 0;

    for _ in 0..permutations {
        all_samples.shuffle(&mut thread_rng());
        let perm_sample1 = &all_samples[..n1];
        let perm_sample2 = &all_samples[n1..];
        let perm_diff = perm_sample1.iter().sum::<f64>() / n1 as f64 - perm_sample2.iter().sum::<f64>() / n2 as f64;
        if perm_diff.abs() >= observed_diff.abs() {
            count += 1;
        }
    }

    count as f64 / permutations as f64
}

fn analyze_data(sample1: &[i32], sample2: &[i32]) -> f64 {
    let sample1_f64: Vec<f64> = sample1.iter().map(|&x| x as f64).collect();
    let sample2_f64: Vec<f64> = sample2.iter().map(|&x| x as f64).collect();
    permutation_test(&sample1_f64, &sample2_f64, 10000)
}

fn main() {
    let sample1 = vec![23, 45, 12, 67, 34];
    let sample2 = vec![34, 56, 23, 78, 45];
    let result = analyze_data(&sample1, &sample2);
    println!("{}", result);
}