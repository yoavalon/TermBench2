use rand::Rng;

fn monte_carlo_option_pricing(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> f64 {
    let dt = T / (N as f64);
    let mut S = vec![0.0; N + 1];
    S[0] = S0;
    for i in 1..=N {
        S[i] = S[i - 1] * (r - 0.5 * sigma.powi(2) * dt + sigma * (dt.sqrt() * rand::thread_rng().gen::<f64>() * 2.0 - 1.0)).exp();
    }
    let payoff = f64::max(S[N] - K, 0.0);
    let option_price = payoff * (-r * T).exp();
    option_price
}

fn main() {
    let result = monte_carlo_option_pricing(100.0, 100.0, 1.0, 0.05, 0.2, 1000);
    println!("{}", result);
}