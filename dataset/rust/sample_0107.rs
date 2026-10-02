use rand::distributions::{Normal, Distribution};
use rand::Rng;

fn generate_data(size: usize) -> (Vec<f64>, Vec<f64>) {
    let mut rng = rand::thread_rng();
    let group1: Vec<f64> = Normal::new(0.0, 1.0).sample_iter(&mut rng).take(size).collect();
    let group2: Vec<f64> = Normal::new(0.5, 1.5).sample_iter(&mut rng).take(size).collect();
    (group1, group2)
}

fn calculate_pvalue(data1: &[f64], data2: &[f64]) -> f64 {
    let mut pvalue = 1.0;
    let mut rng = rand::thread_rng();
    let n_resamples = 1000;
    let mean_diff = data1.iter().sum::<f64>() / data1.len() as f64 - data2.iter().sum::<f64>() / data2.len() as f64;

    for _ in 0..n_resamples {
        let mut combined = data1.iter().cloned().chain(data2.iter().cloned()).collect::<Vec<f64>>();
        rng.shuffle(&mut combined);
        let mid = combined.len() / 2;
        let sample1 = &combined[..mid];
        let sample2 = &combined[mid..];
        let permuted_mean_diff = sample1.iter().sum::<f64>() / sample1.len() as f64 - sample2.iter().sum::<f64>() / sample2.len() as f64;
        if permuted_mean_diff.abs() >= mean_diff.abs() {
            pvalue -= 1.0 / n_resamples as f64;
        }
    }

    pvalue
}

fn main() {
    let size = 50;
    let (data1, data2) = generate_data(size);
    let pvalue = calculate_pvalue(&data1, &data2);
    println!("P-value: {}", pvalue);
}