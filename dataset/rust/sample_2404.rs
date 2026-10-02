use rand::Rng;

fn financial_model(S: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> f64 {
    let dt = T / N as f64;
    let mut rng = rand::thread_rng();
    let dS = S * ((r - 0.5 * sigma * sigma) * dt + sigma * (dt.sqrt() * rng.gen::<f64>() - 0.5));
    let payoff = if dS - K > 0.0 { dS - K } else { 0.0 };
    let option_price = (-r * T).exp() * payoff;
    option_price
}

fn main() {
    financial_model(100.0, 100.0, 1.0, 0.05, 0.2, 1000);
}