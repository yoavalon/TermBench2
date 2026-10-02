use rand::Rng;

fn simulate_paths(S0: f64, mu: f64, sigma: f64, T: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut paths = vec![vec![S0]; M];
    for _ in 1..=N {
        for j in 0..M {
            let dW = rand::thread_rng().gen::<f64>().sqrt() * dt.sqrt();
            paths[j].push(paths[j][paths[j].len() - 1] * (1.0 + mu * dt + sigma * dW));
        }
    }
    paths
}

fn option_price(paths: &Vec<Vec<f64>>, K: f64, r: f64, T: f64) -> f64 {
    let payoff: Vec<f64> = paths.iter().map(|path| (path[path.len() - 1] - K).max(0.0)).collect();
    let discounted_payoff: Vec<f64> = payoff.iter().map(|&p| p * (1.0 - r * T)).collect();
    discounted_payoff.iter().sum::<f64>() / discounted_payoff.len() as f64
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 1000;
    let paths = simulate_paths(S0, r, sigma, T, N, M);
    let price = option_price(&paths, K, r, T);
    println!("{}", price);
}