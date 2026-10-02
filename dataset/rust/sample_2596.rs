use rand::Rng;

fn simulate_geometric_brownian_motion(S0: f64, mu: f64, sigma: f64, T: f64, N: usize) -> f64 {
    let dt = T / N as f64;
    let mut S = vec![S0];
    for _ in 1..=N {
        let dS = S[S.len() - 1] * (mu * dt + sigma * rand::thread_rng().gen::<f64>().sqrt() * dt.sqrt());
        S.push(S[S.len() - 1] + dS);
    }
    S[S.len() - 1]
}

fn monte_carlo_option_pricing(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> f64 {
    let mut C = 0.0;
    for _ in 0..M {
        let ST = simulate_geometric_brownian_motion(S0, r, sigma, T, N);
        C += ST.max(K);
    }
    C / M as f64
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 1000;
    let option_price = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M);
    println!("{}", option_price);
}