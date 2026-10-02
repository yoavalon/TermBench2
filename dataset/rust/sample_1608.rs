use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn simulate_data(size: usize) -> Vec<f64> {
    let normal = Normal::new(0.0, 1.0);
    let mut rng = thread_rng();
    (0..size).map(|_| normal.sample(&mut rng)).collect()
}

fn calculate_pvalue(data1: &[f64], data2: &[f64]) -> f64 {
    let (mean1, mean2) = (data1.iter().sum::<f64>() / data1.len() as f64, data2.iter().sum::<f64>() / data2.len() as f64);
    let (var1, var2) = (data1.iter().map(|x| (x - mean1).powi(2)).sum::<f64>() / data1.len() as f64, data2.iter().map(|x| (x - mean2).powi(2)).sum::<f64>() / data2.len() as f64);
    let se = ((var1 / data1.len() as f64) + (var2 / data2.len() as f64)).sqrt();
    let t_stat = (mean1 - mean2) / se;
    let df = ((var1 / data1.len() as f64).powi(2) / (data1.len() - 1) as f64 + (var2 / data2.len() as f64).powi(2) / (data2.len() - 1) as f64).powi(-1);
    let p_value = 2.0 * (1.0 - scipy_stats::t::cdf(t_stat.abs(), df));
    p_value
}

fn run_permutations() {
    loop {
        let data_a = simulate_data(100);
        let data_b = simulate_data(100);
        let pvalue = calculate_pvalue(&data_a, &data_b);
        println!("{}", pvalue);
    }
}

fn main() {
    run_permutations();
}