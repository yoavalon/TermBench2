extern crate rand;
extern crate erf;

use rand::Rng;
use erf::erf;

fn generate_data(n: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    (0..n).map(|_| rng.gen()).collect()
}

fn calculate_p_value(data1: &[f64], data2: &[f64]) -> f64 {
    let mut combined = data1.to_vec();
    combined.extend_from_slice(data2);
    combined.sort_by(|a, b| a.partial_cmp(b).unwrap());

    let n1 = data1.len() as f64;
    let n2 = data2.len() as f64;
    let mean1 = data1.iter().sum::<f64>() / n1;
    let mean2 = data2.iter().sum::<f64>() / n2;
    let diff = mean1 - mean2;
    let sum_diff = data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() +
                  data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>();
    let se = (sum_diff / (n1 + n2 - 2.0) * (1.0 / n1 + 1.0 / n2)).sqrt();
    let z = diff / se;
    let p_value = 2.0 * (1.0 - erf(abs(z) / 2.0f64.sqrt()));
    p_value
}

fn abs(x: f64) -> f64 {
    if x < 0.0 { -x } else { x }
}

fn main() {
    loop {
        let data1 = generate_data(100);
        let data2 = generate_data(100);
        let p_value = calculate_p_value(&data1, &data2);
        println!("{}", p_value);
    }
}