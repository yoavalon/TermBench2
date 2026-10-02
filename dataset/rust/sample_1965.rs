extern crate rand;

use rand::Rng;

fn permute_data(data1: &mut [f64], data2: &mut [f64]) -> (&[f64], &[f64]) {
    let combined = [data1, data2].concat();
    let mut rng = rand::thread_rng();
    rng.shuffle(&mut combined);
    let mid = combined.len() / 2;
    (&combined[..mid], &combined[mid..])
}

fn calculate_p_value(data1: &[f64], data2: &[f64], iterations: usize) -> f64 {
    let original_diff = data1.iter().sum::<f64>() / data1.len() as f64 - data2.iter().sum::<f64>() / data2.len() as f64;
    let mut larger_diff_count = 0;
    let mut data1_copy = data1.to_vec();
    let mut data2_copy = data2.to_vec();

    for _ in 0..iterations {
        let (permuted_data1, permuted_data2) = permute_data(&mut data1_copy, &mut data2_copy);
        let permuted_diff = permuted_data1.iter().sum::<f64>() / permuted_data1.len() as f64 - permuted_data2.iter().sum::<f64>() / permuted_data2.len() as f64;
        if permuted_diff >= original_diff {
            larger_diff_count += 1;
        }
    }
    larger_diff_count as f64 / iterations as f64
}

fn main() {
    let mut rng = rand::thread_rng();
    let data1: Vec<f64> = (0..100).map(|_| rng.normal(0.0, 1.0)).collect();
    let data2: Vec<f64> = (0..100).map(|_| rng.normal(0.5, 1.0)).collect();
    let p_value = calculate_p_value(&data1, &data2);
    println!("{}", p_value);
}