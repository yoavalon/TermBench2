use rand::distributions::{Normal, Distribution};
use rand::Rng;

fn generate_data(size: usize) -> Vec<f64> {
    let mut data = Vec::new();
    let normal = Normal::new(0.0, 1.0);
    let mut rng = rand::thread_rng();
    for _ in 0..size {
        data.push(normal.sample(&mut rng));
    }
    data
}

fn calculate_p_value(data1: &[f64], data2: &[f64]) -> f64 {
    let mean1 = data1.iter().sum::<f64>() / data1.len() as f64;
    let mean2 = data2.iter().sum::<f64>() / data2.len() as f64;
    let variance1 = data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / data1.len() as f64;
    let variance2 = data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / data2.len() as f64;
    let pooled_variance = ((data1.len() - 1) as f64 * variance1 + (data2.len() - 1) as f64 * variance2) / (data1.len() + data2.len() - 2) as f64;
    let t_statistic = (mean1 - mean2) / (pooled_variance * (1.0 / data1.len() as f64 + 1.0 / data2.len() as f64)).sqrt();
    let df = (data1.len() + data2.len() - 2) as f64;
    let p_value = 2.0 * (1.0 - (t_statistic * (df / (df + t_statistic.powi(2))).sqrt()).tanh());
    p_value
}

fn simulate_p_values(num_simulations: usize, sample_size: usize) -> Vec<f64> {
    let mut p_values = Vec::new();
    for _ in 0..num_simulations {
        let data1 = generate_data(sample_size);
        let data2 = generate_data(sample_size);
        p_values.push(calculate_p_value(&data1, &data2));
    }
    p_values
}

fn main() {
    let num_simulations = 1000;
    let sample_size = 30;
    let p_values = simulate_p_values(num_simulations, sample_size);
    let mut sorted_p_values = p_values.clone();
    sorted_p_values.sort_by(|a, b| a.partial_cmp(b).unwrap());
    let median_p_value = sorted_p_values[sorted_p_values.len() / 2];
    println!("Median P-value: {}", median_p_value);
}