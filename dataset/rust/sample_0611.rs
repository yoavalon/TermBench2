use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn monte_carlo_pricing(S: f64, K: f64, T: f64, r: f64, sigma: f64, N: i32, M: i32) -> f64 {
    let dt = T / N as f64;
    let mut paths = vec![vec![S]; M as usize];
    let normal = Normal::new(0.0, 1.0);

    for _ in 1..=N {
        for j in 0..M {
            let mut rng = thread_rng();
            let z = normal.sample(&mut rng);
            paths[j as usize].push(paths[j as usize][paths[j as usize].len() - 1] * (r - 0.5 * sigma.powi(2)) * dt + sigma * dt.sqrt() * z);
        }
    }

    exp(-r * T) * paths.iter().map(|path| path[path.len() - 1].max(K) - K).sum::<f64>() / M as f64
}

fn main() {
    println!("{}", monte_carlo_pricing(100.0, 100.0, 1.0, 0.05, 0.2, 100, 10000));
}