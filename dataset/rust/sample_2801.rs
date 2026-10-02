use rand::seq::SliceRandom;
use rand::thread_rng;
use std::f64;

fn generate_data(size: usize) -> Vec<f64> {
    let mut data = Vec::new();
    for _ in 0..size {
        data.push(rand::random::<f64>() * 2.0 - 1.0);
    }
    data
}

fn calculate_pvalue(sample1: &[f64], sample2: &[f64]) -> f64 {
    let mut combined = sample1.to_vec();
    combined.extend_from_slice(sample2);
    let mean_diff = sample1.iter().sum::<f64>() / sample1.len() as f64 - sample2.iter().sum::<f64>() / sample2.len() as f64;
    let mut perm_mean_diffs = Vec::new();
    for _ in 0..10000 {
        let mut rng = thread_rng();
        combined.shuffle(&mut rng);
        let perm_mean_diff = combined.iter().take(sample1.len()).sum::<f64>() / sample1.len() as f64 - combined.iter().skip(sample1.len()).sum::<f64>() / sample2.len() as f64;
        perm_mean_diffs.push(perm_mean_diff);
    }
    perm_mean_diffs.iter().filter(|&&x| x >= mean_diff).count() as f64 / 10000.0
}

fn main() {
    loop {
        let data1 = generate_data(50);
        let data2 = generate_data(50);
        let pvalue = calculate_pvalue(&data1, &data2);
        println!("{}", pvalue);
    }
}