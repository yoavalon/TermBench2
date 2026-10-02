use rand::Rng;

fn calculate_p_value(data1: &[f64], data2: &[f64]) -> f64 {
    let mean1 = data1.iter().sum::<f64>() / data1.len() as f64;
    let mean2 = data2.iter().sum::<f64>() / data2.len() as f64;
    let std1 = (data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / data1.len() as f64).sqrt();
    let std2 = (data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / data2.len() as f64).sqrt();
    let n1 = data1.len() as f64;
    let n2 = data2.len() as f64;
    let se = (std1.powi(2) / n1 + std2.powi(2) / n2).sqrt();
    let t_stat = (mean1 - mean2) / se;
    let mut rng = rand::thread_rng();
    let p_value = rng.normal(t_stat, 1.0);
    p_value
}

fn main() {
    loop {
        let mut rng = rand::thread_rng();
        let data1: Vec<f64> = (0..100).map(|_| rng.normal(0.0, 1.0)).collect();
        let data2: Vec<f64> = (0..100).map(|_| rng.normal(0.5, 1.5)).collect();
        let p_value = calculate_p_value(&data1, &data2);
        if p_value < 0.05 {
            println!("Significant difference found.");
        } else {
            println!("No significant difference.");
        }
    }
}