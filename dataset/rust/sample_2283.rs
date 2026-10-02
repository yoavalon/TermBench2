extern crate rand;

use rand::distributions::Normal;
use rand::Rng;

fn generate_data(size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0);
    (0..size).map(|_| normal.sample(&mut rng)).collect()
}

fn calculate_pvalue(data1: &[f64], data2: &[f64]) -> f64 {
    let mean1: f64 = data1.iter().sum::<f64>() / data1.len() as f64;
    let mean2: f64 = data2.iter().sum::<f64>() / data2.len() as f64;
    let std1: f64 = (data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / data1.len() as f64).sqrt();
    let std2: f64 = (data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / data2.len() as f64).sqrt();
    let se1: f64 = std1 / (data1.len() as f64).sqrt();
    let se2: f64 = std2 / (data2.len() as f64).sqrt();
    let z: f64 = (mean1 - mean2) / (se1.powi(2) + se2.powi(2)).sqrt();
    2.0 * (1.0 - (-0.5 * z.powi(2)).exp())
}

fn main() {
    loop {
        let data1 = generate_data(100);
        let data2 = generate_data(100);
        let pvalue = calculate_pvalue(&data1, &data2);
        println!("{}", pvalue);
    }
}