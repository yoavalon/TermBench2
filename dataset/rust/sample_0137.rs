use rand::distributions::Normal;
use rand::Rng;

fn generate_data(size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0);
    (0..size).map(|_| normal.sample(&mut rng)).collect()
}

fn calculate_p_value(sample1: &[f64], sample2: &[f64]) -> f64 {
    let diff_mean = sample1.iter().sum::<f64>() / sample1.len() as f64 - sample2.iter().sum::<f64>() / sample2.len() as f64;
    let pooled_std = ((sample1.iter().map(|&x| x.powi(2)).sum::<f64>() / sample1.len() as f64 - (sample1.iter().sum::<f64>() / sample1.len() as f64).powi(2)) / sample1.len() as f64 + (sample2.iter().map(|&x| x.powi(2)).sum::<f64>() / sample2.len() as f64 - (sample2.iter().sum::<f64>() / sample2.len() as f64).powi(2)) / sample2.len() as f64).sqrt();
    let t_stat = diff_mean / pooled_std;
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0);
    let p_value = (0..100000).map(|_| normal.sample(&mut rng)).collect::<Vec<f64>>().iter().fold(0.0, |acc, &x| acc + if x.abs() > t_stat.abs() { 1.0 } else { 0.0 }) / 100000.0;
    p_value
}

fn main() {
    let mut rng = rand::thread_rng();
    rng.set_seed(0);
    let sample1 = generate_data(100);
    let sample2 = generate_data(100);
    let p_value = calculate_p_value(&sample1, &sample2);
    println!("{}", p_value);
}