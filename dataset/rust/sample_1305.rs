use rand::Rng;
use rand_distr::{Normal, Distribution};

fn generate_data(size: usize) -> Vec<f64> {
    let normal = Normal::new(0.0, 1.0).unwrap();
    let mut rng = rand::thread_rng();
    (0..size).map(|_| normal.sample(&mut rng)).collect()
}

fn ttest_ind(data1: &[f64], data2: &[f64]) -> f64 {
    let mean1 = data1.iter().sum::<f64>() / data1.len() as f64;
    let mean2 = data2.iter().sum::<f64>() / data2.len() as f64;
    let var1 = data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / data1.len() as f64;
    let var2 = data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / data2.len() as f64;
    let pooled_var = (var1 * data1.len() as f64 + var2 * data2.len() as f64) / (data1.len() + data2.len()) as f64;
    let se = (pooled_var * (1.0 / data1.len() as f64 + 1.0 / data2.len() as f64)).sqrt();
    (mean1 - mean2).abs() / se
}

fn perform_permutation_test(data1: &[f64], data2: &[f64], iterations: usize) -> (f64, Vec<f64>) {
    let original_p_value = ttest_ind(data1, data2);
    let mut p_values = Vec::with_capacity(iterations);
    let mut combined_data: Vec<f64> = data1.iter().cloned().chain(data2.iter().cloned()).collect();
    for _ in 0..iterations {
        let mut rng = rand::thread_rng();
        combined_data.shuffle(&mut rng);
        let new_p_value = ttest_ind(&combined_data[..data1.len()], &combined_data[data1.len()..]);
        p_values.push(new_p_value);
    }
    (original_p_value, p_values)
}

fn main() {
    let data1 = generate_data(50);
    let data2 = generate_data(50);
    let iterations = 1000;
    let (original_p_value, p_values) = perform_permutation_test(&data1, &data2, iterations);
    println!("{}", original_p_value);
    println!("{}", p_values.iter().filter(|&&p| p < original_p_value).count() as f64 / iterations as f64);
}