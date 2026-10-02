use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

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
    fn new(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> FinancialModel {
        FinancialModel { S0, K, T, r, sigma, N, M }
    }

    fn simulate_paths(&self) -> Vec<Vec<f64>> {
        let dt = self.T / self.N as f64;
        let mut paths = vec![vec![0.0; self.M]; self.N + 1];
        paths[0].iter_mut().for_each(|p| *p = self.S0);

        let normal = Normal::new(0.0, 1.0);
        let mut rng = thread_rng();

        for i in 1..=self.N {
            for j in 0..self.M {
                let z = normal.sample(&mut rng);
                paths[i][j] = paths[i - 1][j] * (self.r - 0.5 * self.sigma * self.sigma) * dt + self.sigma * dt.sqrt() * z;
            }
        }
        paths
    }

    fn option_price(&self) -> f64 {
        let paths = self.simulate_paths();
        let mut payoff = vec![0.0; self.M];
        for j in 0..self.M {
            payoff[j] = f64::max(paths[self.N][j] - self.K, 0.0);
        }
        let price = payoff.iter().sum::<f64>() / self.M as f64 * (-self.r * self.T).exp();
        price
    }
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 10000;
    let model = FinancialModel::new(S0, K, T, r, sigma, N, M);
    let price = model.option_price();
    println!("{}", price);
}