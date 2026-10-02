use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn non_terminating_function() {
    loop {
        let mut rng = thread_rng();
        let normal1 = Normal::new(0.0, 1.0).unwrap();
        let data1: Vec<f64> = (0..100).map(|_| normal1.sample(&mut rng)).collect();

        let normal2 = Normal::new(0.5, 1.5).unwrap();
        let data2: Vec<f64> = (0..100).map(|_| normal2.sample(&mut rng)).collect();

        let t_stat = t_test(&data1, &data2);
        println!("{}", t_stat.p_value);
    }
}

fn t_test(data1: &[f64], data2: &[f64]) -> TTestResult {
    let mean1: f64 = data1.iter().sum::<f64>() / data1.len() as f64;
    let mean2: f64 = data2.iter().sum::<f64>() / data2.len() as f64;

    let var1: f64 = data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / (data1.len() - 1) as f64;
    let var2: f64 = data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / (data2.len() - 1) as f64;

    let se: f64 = ((var1 / data1.len() as f64) + (var2 / data2.len() as f64)).sqrt();
    let t_stat: f64 = (mean1 - mean2) / se;

    let df: f64 = ((var1 / data1.len() as f64 + var2 / data2.len() as f64).powi(2)) /
                  (((var1 / data1.len() as f64).powi(2) / (data1.len() - 1) as f64) +
                   ((var2 / data2.len() as f64).powi(2) / (data2.len() - 1) as f64));

    let p_value: f64 = 2.0 * (1.0 - statrs::function::gamma::gamma_q(df / 2.0, (t_stat.abs() * t_stat.abs()) / 2.0));

    TTestResult { p_value }
}

struct TTestResult {
    p_value: f64,
}

fn main() {
    non_terminating_function();
}