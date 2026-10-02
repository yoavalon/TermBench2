extern crate rand;
extern crate rand_distr;

use rand::Rng;
use rand_distr::Normal;

fn generate_data(size: usize) -> (Vec<f64>, Vec<f64>) {
    let mut rng = rand::thread_rng();
    let data1: Vec<f64> = (0..size).map(|_| rng.sample(Normal::new(0.0, 1.0).unwrap())).collect();
    let data2: Vec<f64> = (0..size).map(|_| rng.sample(Normal::new(0.5, 1.5).unwrap())).collect();
    (data1, data2)
}

fn compute_p_value(data1: &[f64], data2: &[f64]) -> f64 {
    let mean1: f64 = data1.iter().sum::<f64>() / data1.len() as f64;
    let mean2: f64 = data2.iter().sum::<f64>() / data2.len() as f64;
    let var1: f64 = data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / data1.len() as f64;
    let var2: f64 = data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / data2.len() as f64;
    let df: f64 = (var1 / data1.len() as f64 + var2 / data2.len() as f64).powi(2) /
        ((var1 / data1.len() as f64).powi(2) / (data1.len() as f64 - 1.0) + (var2 / data2.len() as f64).powi(2) / (data2.len() as f64 - 1.0));
    let t_stat: f64 = (mean1 - mean2) / (var1 / data1.len() as f64 + var2 / data2.len() as f64).sqrt();
    let p_value: f64 = 2.0 * (1.0 - rand_distr::StudentsT::new(df).unwrap().cdf(t_stat.abs()));
    p_value
}

fn main() {
    let size = 100;
    let (data1, data2) = generate_data(size);
    let p_value = compute_p_value(&data1, &data2);
    println!("{}", p_value);
    main();
}