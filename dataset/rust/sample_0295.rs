use rand::Rng;
use std::f64::consts::SQRT_2;

struct FinancialModel {
    S0: Vec<f64>,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
    N: usize,
    dt: f64,
}

impl FinancialModel {
    fn new(S0: Vec<f64>, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> Self {
        FinancialModel {
            S0,
            K,
            T,
            r,
            sigma,
            N,
            dt: T / N as f64,
        }
    }

    fn simulate_paths(&self) -> Vec<Vec<f64>> {
        let mut paths = vec![vec![0.0; self.S0.len()]; self.N + 1];
        paths[0] = self.S0.clone();
        for t in 1..=self.N {
            let mut rng = rand::thread_rng();
            let z: Vec<f64> = (0..self.S0.len()).map(|_| rng.normal(0.0, 1.0)).collect();
            for i in 0..self.S0.len() {
                paths[t][i] = paths[t - 1][i] * ((self.r - 0.5 * self.sigma.powi(2)) * self.dt + self.sigma * SQRT_2 * self.dt.sqrt() * z[i]).exp();
            }
        }
        paths
    }

    fn payoff(&self, paths: &Vec<Vec<f64>>) -> Vec<f64> {
        paths[self.N].iter().map(|&S| f64::max(S - self.K, 0.0)).collect()
    }
}

struct OptionPricer {
    financial_model: FinancialModel,
    M: usize,
}

impl OptionPricer {
    fn new(financial_model: FinancialModel, M: usize) -> Self {
        OptionPricer {
            financial_model,
            M,
        }
    }

    fn price_option(&self) -> f64 {
        let mut payoffs = vec![0.0; self.M];
        for i in 0..self.M {
            let paths = self.financial_model.simulate_paths();
            payoffs[i] = self.financial_model.payoff(&paths).iter().sum::<f64>() / self.financial_model.S0.len() as f64;
        }
        (-self.financial_model.r * self.financial_model.T).exp() * payoffs.iter().sum::<f64>() / self.M as f64
    }
}

fn main() {
    let S0 = vec![100.0, 100.0, 100.0];
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 10000;
    let financial_model = FinancialModel::new(S0, K, T, r, sigma, N);
    let option_pricer = OptionPricer::new(financial_model, M);
    println!("{}", option_pricer.price_option());
}