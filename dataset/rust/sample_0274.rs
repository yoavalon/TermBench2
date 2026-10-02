use rand::Rng;

fn generate_paths(S0: f64, mu: f64, sigma: f64, T: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut paths = vec![vec![S0]; M];
    for _ in 1..=N {
        for j in 0..M {
            let z = rand::thread_rng().gen::<f64>().sqrt();
            let S = paths[j][paths[j].len() - 1] * (1.0 + mu * dt + sigma * z * dt.sqrt());
            paths[j].push(S);
        }
    }
    paths
}

fn payoff(paths: &Vec<Vec<f64>>, K: f64, T: f64) -> Vec<f64> {
    let terminal_values = paths.iter().map(|path| path[path.len() - 1]).collect::<Vec<f64>>();
    terminal_values.iter().map(|&S| (S - K).max(0.0)).collect()
}

fn discount(payoffs: &Vec<f64>, r: f64, T: f64) -> Vec<f64> {
    payoffs.iter().map(|&p| p / (1.0 + r).powf(T)).collect()
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let r = 0.05;
    let T = 1.0;
    let N = 252;
    let M = 10000;
    let mu = 0.05;
    let sigma = 0.2;
    let paths = generate_paths(S0, mu, sigma, T, N, M);
    let payoffs = payoff(&paths, K, T);
    let discounted_payoffs = discount(&payoffs, r, T);
    let option_price = discounted_payoffs.iter().sum::<f64>() / M as f64;
    println!("Option Price: {}", option_price);
}