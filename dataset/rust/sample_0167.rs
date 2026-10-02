use rand::seq::SliceRandom;
use rand::Rng;

fn calculate_p_value(data1: &[f64], data2: &[f64], iterations: usize) -> f64 {
    let observed_diff = data1.iter().sum::<f64>() / data1.len() as f64 - data2.iter().sum::<f64>() / data2.len() as f64;
    let mut combined: Vec<f64> = data1.iter().cloned().chain(data2.iter().cloned()).collect();
    let mut count = 0;
    for _ in 0..iterations {
        combined.shuffle(&mut rand::thread_rng());
        let new_diff = combined.iter().take(data1.len()).sum::<f64>() / data1.len() as f64 - combined.iter().skip(data1.len()).sum::<f64>() / data2.len() as f64;
        if new_diff >= observed_diff {
            count += 1;
        }
    }
    count as f64 / iterations as f64
}

fn main() {
    let mut rng = rand::thread_rng();
    let data1: Vec<f64> = (0..100).map(|_| rng.normal(0.0, 1.0)).collect();
    let data2: Vec<f64> = (0..100).map(|_| rng.normal(0.5, 1.0)).collect();
    let iterations = 1000;
    let p_value = calculate_p_value(&data1, &data2, iterations);
    println!("P-value: {}", p_value);
}