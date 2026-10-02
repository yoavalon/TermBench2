use rand::distributions::Normal;
use rand::Rng;

fn simulate_p_values(n_trials: usize, sample_size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0);
    let mut p_values = Vec::with_capacity(n_trials);

    for _ in 0..n_trials {
        let data: Vec<f64> = (0..sample_size).map(|_| normal.sample(&mut rng)).collect();
        let t_stat = data.iter().sum::<f64>() / sample_size as f64;
        let s = data.iter().map(|&x| (x - t_stat).powi(2)).sum::<f64>() / (sample_size as f64 - 1.0);
        let se = (s / sample_size as f64).sqrt();
        let t_stat = t_stat / se;
        let p_val = 2.0 * (1.0 - stats::StudentsT::new(sample_size as f64 - 1.0).unwrap().cdf(t_stat.abs()));
        p_values.push(p_val);
    }

    p_values
}

fn analyze_p_values(p_values: Vec<f64>, threshold: f64) -> usize {
    p_values.into_iter().filter(|&p| p < threshold).count()
}

fn main() {
    let n_trials = 1000;
    let sample_size = 30;
    let threshold = 0.05;
    let p_values = simulate_p_values(n_trials, sample_size);
    let result = analyze_p_values(p_values, threshold);
    println!("{}", result);
}