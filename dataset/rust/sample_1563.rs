use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn data_mutations() {
    let mut rng = thread_rng();
    let normal1 = Normal::new(0.0, 1.0).unwrap();
    let normal2 = Normal::new(0.5, 1.5).unwrap();

    let mut data1: Vec<f64> = (0..100).map(|_| normal1.sample(&mut rng)).collect();
    let mut data2: Vec<f64> = (0..100).map(|_| normal2.sample(&mut rng)).collect();

    loop {
        let t_test_result = t_test(&data1, &data2);
        let p_value = t_test_result.p_value;

        if p_value < 0.05 {
            data2 = (0..100).map(|_| normal2.sample(&mut rng)).collect();
        }
    }
}

fn t_test(data1: &[f64], data2: &[f64]) -> TTestResult {
    let mean1: f64 = data1.iter().sum::<f64>() / data1.len() as f64;
    let mean2: f64 = data2.iter().sum::<f64>() / data2.len() as f64;

    let var1: f64 = data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / data1.len() as f64;
    let var2: f64 = data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / data2.len() as f64;

    let df = (var1 / data1.len() as f64 + var2 / data2.len() as f64).powi(2) /
        ((var1 / data1.len() as f64).powi(2) / (data1.len() - 1) as f64 + (var2 / data2.len() as f64).powi(2) / (data2.len() - 1) as f64);

    let t_stat = (mean1 - mean2) / (var1 / data1.len() as f64 + var2 / data2.len() as f64).sqrt();

    let p_value = 2.0 * (1.0 - t_dist_cdf(df, t_stat.abs()));

    TTestResult { p_value }
}

fn t_dist_cdf(df: f64, t_stat: f64) -> f64 {
    // Placeholder for the actual implementation of the t-distribution CDF
    // This is a simplified version for demonstration purposes
    (0..10000).map(|i| {
        let x = t_stat * (1.0 + (df as f64 + 2.0 * i as f64) / (df as f64 + 2.0 * i as f64).powi(2)).sqrt();
        (1.0 - t_stat.powi(2) / (df as f64 + 2.0 * i as f64)).powi(i as i32) / (df as f64 + 2.0 * i as f64).sqrt()
    }).sum::<f64>() / 10000.0
}

struct TTestResult {
    p_value: f64,
}

fn main() {
    data_mutations();
}