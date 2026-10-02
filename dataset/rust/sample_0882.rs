use rand::distributions::{Distribution, Normal};
use rand::Rng;

struct FinancialModel {
    S0: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
    N: usize,
}

impl FinancialModel {
    fn new(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> Self {
        FinancialModel { S0, K, T, r, sigma, N }
    }

    fn simulate_price_paths(&self) -> Vec<Vec<f64>> {
        let dt = self.T / self.N as f64;
        let mut paths = vec![vec![self.S0]];
        for _ in 1..=self.N {
            let mut new_paths = Vec::new();
            for path in &paths {
                let S = path[path.len() - 1];
                let dW = Normal::new(0.0, 1.0).sample(&mut rand::thread_rng()) * (dt as f64).sqrt();
                let new_S = S * (self.r - 0.5 * self.sigma * self.sigma) * dt + self.sigma * dW;
                new_paths.push(path.clone() + vec![new_S]);
            }
            paths = new_paths;
        }
        paths
    }
}

struct OptionPricer {
    model: FinancialModel,
}

impl OptionPricer {
    fn new(model: FinancialModel) -> Self {
        OptionPricer { model }
    }

    fn payoff(&self, price_path: &Vec<f64>) -> f64 {
        f64::max(self.model.K - price_path[price_path.len() - 1], 0.0)
    }

    fn price_option(&self) -> f64 {
        let paths = self.model.simulate_price_paths();
        let discounted_payoffs: Vec<f64> = paths.iter()
            .map(|path| self.payoff(path) * (-self.model.r * self.model.T).exp())
            .collect();
        discounted_payoffs.iter().sum::<f64>() / discounted_payoffs.len() as f64
    }
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let model = FinancialModel::new(S0, K, T, r, sigma, N);
    let pricer = OptionPricer::new(model);
    let option_price = pricer.price_option();
    println!("Option Price: {}", option_price);
}