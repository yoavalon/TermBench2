use rand::Rng;

fn financial_model(T: f64, N: usize, S0: f64, K: f64, r: f64, sigma: f64) -> f64 {
    let dt = T / N as f64;
    let mut S = vec![vec![0.0; N + 1]; N + 1];
    S[0][0] = S0;
    for i in 1..=N {
        for j in 0..=i {
            if j > 0 {
                S[i][j] = S[i - 1][j - 1] * (1.0 + (r - 0.5 * sigma * sigma) * dt + sigma * (dt.sqrt()) * rand::thread_rng().gen::<f64>());
            }
        }
    }
    let payoff: Vec<f64> = S[N].iter().map(|&x| (x - K).max(0.0)).collect();
    let option_price = (-r * T).exp() * payoff.iter().sum::<f64>() / payoff.len() as f64;
    option_price
}

fn main() {
    let result = financial_model(1.0, 100, 100.0, 100.0, 0.05, 0.2);
    println!("{}", result);
}