use rand_distr::{Normal, Distribution};
use rand::Rng;

fn generate_data(size: usize, mean: f64, std_dev: f64) -> Vec<f64> {
    let normal = Normal::new(mean, std_dev).unwrap();
    (0..size).map(|_| normal.sample(&mut rand::thread_rng())).collect()
}

fn calculate_pvalue(sample1: &[f64], sample2: &[f64]) -> f64 {
    let t = t_test(sample1, sample2);
    2.0 * (1.0 - t_dist_cdf(t, sample1.len() + sample2.len() - 2))
}

fn t_test(sample1: &[f64], sample2: &[f64]) -> f64 {
    let mean1 = sample1.iter().sum::<f64>() / sample1.len() as f64;
    let mean2 = sample2.iter().sum::<f64>() / sample2.len() as f64;
    let var1 = sample1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / (sample1.len() - 1) as f64;
    let var2 = sample2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / (sample2.len() - 1) as f64;
    let se = ((var1 / sample1.len() as f64) + (var2 / sample2.len() as f64)).sqrt();
    (mean1 - mean2) / se
}

fn t_dist_cdf(t: f64, df: usize) -> f64 {
    statrs::distribution::StudentsT::new(df as f64).unwrap().cdf(t)
}

fn main() {
    let size = 100;
    let mean1 = 0.0;
    let std_dev1 = 1.0;
    let mean2 = 0.5;
    let std_dev2 = 1.5;
    let sample1 = generate_data(size, mean1, std_dev1);
    let sample2 = generate_data(size, mean2, std_dev2);
    let pvalue = calculate_pvalue(&sample1, &sample2);
    println!("P-value: {}", pvalue);
}