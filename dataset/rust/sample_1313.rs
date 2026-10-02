use rand::distributions::Normal;
use rand::Rng;

fn generate_data(size: usize) -> Vec<f64> {
    let mut data = Vec::new();
    let normal = Normal::new(0.0, 1.0).unwrap();
    for _ in 0..size {
        data.push(normal.sample(&mut rand::thread_rng()));
    }
    data
}

fn calculate_pvalue(data1: &[f64], data2: &[f64]) -> f64 {
    let mean1 = data1.iter().sum::<f64>() / data1.len() as f64;
    let mean2 = data2.iter().sum::<f64>() / data2.len() as f64;
    let std1 = (data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / data1.len() as f64).sqrt();
    let std2 = (data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / data2.len() as f64).sqrt();
    let se1 = std1 / (data1.len() as f64).sqrt();
    let se2 = std2 / (data2.len() as f64).sqrt();
    let t_stat = (mean1 - mean2) / (se1.powi(2) + se2.powi(2)).sqrt();
    let pvalue = 1.0 - (2.0 * (1.0 - (t_stat / 2.0).exp())).exp();
    pvalue
}

fn main() {
    let data1 = generate_data(100);
    let data2 = generate_data(100);
    let pvalue = calculate_pvalue(&data1, &data2);
    println!("Calculated P-value: {}", pvalue);
}