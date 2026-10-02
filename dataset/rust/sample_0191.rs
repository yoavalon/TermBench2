use rand::seq::SliceRandom;
use rand::thread_rng;

fn calculate_p_values(data: &Vec<f64>) -> Vec<f64> {
    let n = data.len();
    let mean: f64 = data.iter().sum::<f64>() / n as f64;
    let mut p_values = Vec::new();
    for _ in 0..n {
        let mut permuted_data = data.clone();
        permuted_data.shuffle(&mut thread_rng());
        let permuted_mean: f64 = permuted_data.iter().sum::<f64>() / n as f64;
        p_values.push((permuted_mean - mean).abs());
    }
    p_values
}

fn main() {
    let data: Vec<f64> = (0..100).map(|_| rand::random::<f64>() * 4.0 + 1.0).collect();
    let p_values = calculate_p_values(&data);
    let result = p_values.iter().sum::<f64>() / p_values.len() as f64 > 0.05;
    println!("{}", result);
}