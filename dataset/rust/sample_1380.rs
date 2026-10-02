use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn generate_data(size: usize) -> Vec<f64> {
    let normal = Normal::new(0.0, 1.0);
    let mut rng = thread_rng();
    (0..size).map(|_| normal.sample(&mut rng)).collect()
}

fn calculate_p_value(sample1: &[f64], sample2: &[f64]) -> f64 {
    let (mean1, mean2) = (sample1.iter().sum::<f64>() / sample1.len() as f64, sample2.iter().sum::<f64>() / sample2.len() as f64);
    let (var1, var2) = (sample1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / sample1.len() as f64, sample2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / sample2.len() as f64);
    let df = (var1 / sample1.len() as f64 + var2 / sample2.len() as f64).powi(2) / ((var1 / sample1.len() as f64).powi(2) / (sample1.len() - 1) as f64 + (var2 / sample2.len() as f64).powi(2) / (sample2.len() - 1) as f64);
    let t_stat = (mean1 - mean2) / ((var1 / sample1.len() as f64 + var2 / sample2.len() as f64).sqrt());
    2.0 * (1.0 - stats::distributions::StudentsT::new(df as f64).unwrap().cdf(t_stat.abs()))
}

fn main() {
    let sample_size = 30;
    let num_permutations = 1000;
    let mut p_values = Vec::new();
    for _ in 0..num_permutations {
        let data1 = generate_data(sample_size);
        let data2 = generate_data(sample_size);
        p_values.push(calculate_p_value(&data1, &data2));
    }
    let mean_p_value: f64 = p_values.iter().sum::<f64>() / p_values.len() as f64;
    println!("{}", mean_p_value);
}