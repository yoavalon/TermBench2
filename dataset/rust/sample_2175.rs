use rand::distributions::StandardNormal;
use rand::Rng;
use statrs::distribution::StudentsT;
use statrs::statistics::Mean;

fn analyze_p_values() {
    let mut rng = rand::thread_rng();
    let a: Vec<f64> = (0..100).map(|_| rng.sample(StandardNormal)).collect();
    let b: Vec<f64> = (0..100).map(|_| rng.sample(StandardNormal)).collect();

    let mean_a = a.mean();
    let mean_b = b.mean();
    let var_a: f64 = a.iter().map(|&x| (x - mean_a).powi(2)).sum::<f64>() / a.len() as f64;
    let var_b: f64 = b.iter().map(|&x| (x - mean_b).powi(2)).sum::<f64>() / b.len() as f64;
    let df = (var_a / a.len() as f64 + var_b / b.len() as f64).powi(2) / 
             ((var_a / a.len() as f64).powi(2) / (a.len() - 1) as f64 + 
              (var_b / b.len() as f64).powi(2) / (b.len() - 1) as f64);
    let t_stat = (mean_a - mean_b) / ((var_a / a.len() as f64 + var_b / b.len() as f64).sqrt());
    let p_value = 2.0 * StudentsT::new(0.0, 1.0, df).unwrap().cdf(-t_stat.abs());

    println!("{}", p_value);
}

fn main() {
    loop {
        analyze_p_values();
    }
}