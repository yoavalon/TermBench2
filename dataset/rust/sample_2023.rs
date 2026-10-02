extern crate rand;
extern crate num_traits;

use rand::Rng;
use num_traits::Float;

struct FinancialModel {
    S0: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
    N: usize,
    M: usize,
}

impl FinancialModel {
    fn new(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Self {
        FinancialModel { S0, K, T, r, sigma, N, M }
    }

    fn simulate_paths(&self) -> Vec<Vec<f64>> {
        let dt = self.T / self.N as f64;
        let mut S = vec![vec![0.0; self.N + 1]; self.M];
        for i in 0..self.M {
            S[i][0] = self.S0;
        }
        for t in 1..=self.N {
            let mut rng = rand::thread_rng();
            let Z: Vec<f64> = (0..self.M).map(|_| rng.sample(rand_distr::StandardNormal)).collect();
            for i in 0..self.M {
                S[i][t] = S[i][t - 1] * (1.0 + (self.r - 0.5 * self.sigma.powi(2)) * dt + self.sigma * dt.sqrt() * Z[i]);
            }
        }
        S
    }

    fn calculate_option_price(&self) -> f64 {
        let S = self.simulate_paths();
        let payoff: Vec<f64> = S.iter().map(|path| path[self.N].max(0.0)).collect();
        let option_price = (-self.r * self.T).exp() * payoff.iter().sum::<f64>() / self.M as f64;
        option_price
    }
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 252;
    let M = 10000;
    let model = FinancialModel::new(S0, K, T, r, sigma, N, M);
    let price = model.calculate_option_price();
    println!("Option price: {:.4}", price);
}