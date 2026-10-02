use rand::distributions::{Distribution, Normal};
use rand::thread_rng;
use std::f64;

struct OptionPricer {
    S: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
    N: usize,
    M: usize,
}

impl OptionPricer {
    fn new(S: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Self {
        OptionPricer { S, K, T, r, sigma, N, M }
    }

    fn simulate_stock_prices(&self) -> Vec<Vec<f64>> {
        let dt = self.T / self.N as f64;
        let mut paths = vec![vec![self.S]; self.M];
        for t in 1..=self.N {
            for i in 0..self.M {
                let z = Normal::new(0.0, 1.0).sample(&mut thread_rng());
                let S_next = paths[i][t - 1] * ((self.r - 0.5 * self.sigma.powi(2)) * dt + self.sigma * z * dt.sqrt()).exp();
                paths[i].push(S_next);
            }
        }
        paths
    }

    fn payoff(&self, paths: &Vec<Vec<f64>>) -> Vec<f64> {
        paths.iter().map(|path| f64::max(path[path.len() - 1] - self.K, 0.0)).collect()
    }

    fn price_option(&self) -> f64 {
        let paths = self.simulate_stock_prices();
        let payoffs = self.payoff(&paths);
        let C = (-self.r * self.T).exp() * payoffs.iter().sum::<f64>() / self.M as f64;
        C
    }
}

fn main() {
    let pricer = OptionPricer::new(S: 100.0, K: 100.0, T: 1.0, r: 0.05, sigma: 0.2, N: 100, M: 1000);
    loop {
        let price = pricer.price_option();
        println!("Option price: {}", price);
    }
}