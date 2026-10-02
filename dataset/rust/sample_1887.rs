use rand::Rng;

fn monte_carlo_option_pricing(S: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> f64 {
    let dt = T / N as f64;
    let mut S_T = vec![0.0; N];
    let mut rng = rand::thread_rng();

    for i in 0..N {
        S_T[i] = S * (r - 0.5 * sigma.powi(2) * dt + sigma * (dt.sqrt() * rng.gen::<f64>() * 2.0 - 1.0)).exp();
    }

    S_T.iter().map(|&x| ((x - K).max(0.0)) * (-r * T).exp()).sum::<f64>() / N as f64
}

fn main() {
    let result = monte_carlo_option_pricing(100.0, 100.0, 1.0, 0.05, 0.2, 10000);
    println!("{}", result);
}