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

    fn simulate_paths(&self) -> Vec<Vec<f64>> {
        let dt = self.T / self.N as f64;
        let mut paths = vec![vec![self.S0]];
        for _ in 0..self.N {
            let mut new_paths = Vec::new();
            for path in &paths {
                let S = path[path.len() - 1];
                let Z = Normal::new(0.0, 1.0).sample(&mut rand::thread_rng());
                let S_new = S * (self.r - 0.5 * self.sigma * self.sigma) * dt.exp() + self.sigma * Z * (dt.sqrt());
                new_paths.push(path.clone().into_iter().chain(std::iter::once(S_new)).collect());
            }
            paths = new_paths;
        }
        paths
    }

    fn calculate_payoff(&self, paths: Vec<Vec<f64>>) -> Vec<f64> {
        paths.into_iter().map(|path| {
            let ST = path[path.len() - 1];
            f64::max(0.0, ST - self.K)
        }).collect()
    }
}

struct PricingEngine {
    model: FinancialModel,
}

impl PricingEngine {
    fn new(model: FinancialModel) -> Self {
        PricingEngine { model }
    }

    fn price_option(&self) -> f64 {
        let paths = self.model.simulate_paths();
        let payoffs = self.model.calculate_payoff(paths);
        let discounted_payoffs: Vec<f64> = payoffs.into_iter().map(|payoff| payoff * (-self.model.r * self.model.T).exp()).collect();
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
    let engine = PricingEngine::new(model);
    let price = engine.price_option();
    println!("{}", price);
}