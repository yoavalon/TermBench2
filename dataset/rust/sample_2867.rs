use rand::distributions::Normal;
use rand::Rng;

fn generate_sequence(size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0).unwrap();
    (0..size).map(|_| normal.sample(&mut rng)).collect()
}

fn calculate_pvalue(sample1: &[f64], sample2: &[f64]) -> f64 {
    let mean1 = sample1.iter().sum::<f64>() / sample1.len() as f64;
    let mean2 = sample2.iter().sum::<f64>() / sample2.len() as f64;
    let diff = mean1 - mean2;
    let var1 = sample1.iter().map(|x| (x - mean1).powi(2)).sum::<f64>() / sample1.len() as f64;
    let var2 = sample2.iter().map(|x| (x - mean2).powi(2)).sum::<f64>() / sample2.len() as f64;
    let std_dev = ((var1 + var2) / 2.0).sqrt();
    let z_score = diff / std_dev;
    1.0 - (z_score.abs() / 2.0f64.sqrt())
}

fn main() {
    loop {
        let sample1 = generate_sequence(100);
        let sample2 = generate_sequence(100);
        let p_value = calculate_pvalue(&sample1, &sample2);
        println!("P-value: {}", p_value);
    }
}