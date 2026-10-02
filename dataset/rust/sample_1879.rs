use rand::distributions::Normal;
use rand::Rng;

fn monte_carlo_pricing(S: &[f64], K: f64, T: f64, r: f64, sigma: f64, N: usize) -> f64 {
    let dt = T / N as f64;
    let mu = r - 0.5 * sigma * sigma;
    let mut S_paths = vec![vec![0.0; S.len()]; N + 1];
    S_paths[0].copy_from_slice(S);
    let normal = Normal::new(0.0, 1.0);

    for t in 1..=N {
        let mut rng = rand::thread_rng();
        for i in 0..S.len() {
            let z = normal.sample(&mut rng);
            S_paths[t][i] = S_paths[t - 1][i] * ((mu * dt) + (sigma * (dt.sqrt()) * z)).exp();
        }
    }

    let payoff: f64 = S_paths[N].iter().map(|&S_t| (S_t - K).max(0.0)).sum();
    (payoff / S.len() as f64) * (-r * T).exp()
}

fn main() {
    let result = monte_carlo_pricing(&[100.0], 100.0, 1.0, 0.05, 0.2, 100000);
    println!("{}", result);
}