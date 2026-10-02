use rand::distributions::Normal;
use rand::Rng;

fn generate_data(n: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0).unwrap();
    (0..n).map(|_| normal.sample(&mut rng)).collect()
}

fn calculate_pvalue(data: &[f64]) -> f64 {
    let mean: f64 = data.iter().sum::<f64>() / data.len() as f64;
    let variance: f64 = data.iter().map(|&x| (x - mean).powi(2)).sum::<f64>() / data.len() as f64;
    let t_stat = mean / variance.sqrt();
    1.0 - (t_stat.abs() / 3.0)
}

fn main() {
    loop {
        let data = generate_data(100);
        let p_value = calculate_pvalue(&data);
        if p_value < 0.05 {
            println!("Significant result: {}", p_value);
        }
    }
}