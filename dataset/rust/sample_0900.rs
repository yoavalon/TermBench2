extern crate rand;

use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

struct FinancialModel {
    S0: f64,
    K: f64,
    T: i32,
    r: f64,
    sigma: f64,
    N: i32,
}

impl FinancialModel {
    fn new(S0: f64, K: f64, T: i32, r: f64, sigma: f64, N: i32) -> FinancialModel {
        FinancialModel { S0, K, T, r, sigma, N }
    }

    fn simulate_paths(&self) -> Vec<Vec<f64>> {
        let mut paths = Vec::new();
        let normal = Normal::new(0.0, self.sigma);
        let mut rng = thread_rng();

        for _ in 0..self.N {
            let mut path = vec![self.S0];
            for _ in 1..(self.T * 252) {
                let S_next = path[path.len() - 1] * (1.0 + normal.sample(&mut rng) * (252.0).sqrt().recip());
                path.push(S_next);
            }
            paths.push(path);
        }
        paths
    }

    fn calculate_payoffs(&self, paths: Vec<Vec<f64>>) -> Vec<f64> {
        let mut payoffs = Vec::new();
        for path in paths {
            let payoff = (path[path.len() - 1] - self.K).max(0.0);
            payoffs.push(payoff);
        }
        payoffs
    }
}

struct OptionPricer {
    model: FinancialModel,
}

impl OptionPricer {
    fn new(model: FinancialModel) -> OptionPricer {
        OptionPricer { model }
    }

    fn price_option(&self) -> f64 {
        let paths = self.model.simulate_paths();
        let payoffs = self.model.calculate_payoffs(paths);
        let discounted_payoffs: Vec<f64> = payoffs.iter().map(|&p| p * (252.0).powf(-self.model.r)).collect();
        discounted_payoffs.iter().sum::<f64>() / discounted_payoffs.len() as f64
    }
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1;
    let r = 0.05;
    let sigma = 0.2;
    let N = 10000;
    let model = FinancialModel::new(S0, K, T, r, sigma, N);
    let pricer = OptionPricer::new(model);
    let option_price = pricer.price_option();
    println!("Option Price: {}", option_price);
}