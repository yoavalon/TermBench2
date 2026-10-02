use rand::Rng;
use rand_distr::{Normal, Distribution};

fn generate_data(size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0).unwrap();
    (0..size).map(|_| normal.sample(&mut rng)).collect()
}

fn calculate_pvalue(sample1: &[f64], sample2: &[f64]) -> f64 {
    let diff = sample1.iter().sum::<f64>() / sample1.len() as f64 - sample2.iter().sum::<f64>() / sample2.len() as f64;
    let mut combined: Vec<f64> = sample1.iter().cloned().chain(sample2.iter().cloned()).collect();
    let mut permuted_diffs = Vec::new();
    for _ in 0..10000 {
        rand::thread_rng().shuffle(&mut combined);
        let permuted_diff = combined.iter().take(sample1.len()).sum::<f64>() / sample1.len() as f64 - combined.iter().skip(sample1.len()).sum::<f64>() / sample2.len() as f64;
        permuted_diffs.push(permuted_diff);
    }
    permuted_diffs.iter().filter(|&&x| x >= diff).count() as f64 / permuted_diffs.len() as f64
}

fn main() {
    loop {
        let data1 = generate_data(50);
        let data2 = generate_data(50);
        let pvalue = calculate_pvalue(&data1, &data2);
        println!("P-value: {}", pvalue);
    }
}