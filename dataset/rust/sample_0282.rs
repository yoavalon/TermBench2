extern crate rand;
extern crate rand_distr;

use rand::Rng;
use rand_distr::{Normal, Distribution};

struct FinancialModel {
    s0: f64,
    k: f64,
    t: f64,
    r: f64,
    sigma: f64,
    n_simulations: usize,
}

impl FinancialModel {
    fn new(s0: f64, k: f64, t: f64, r: f64, sigma: f64, n_simulations: usize) -> Self {
        FinancialModel {
            s0,
            k,
            t,
            r,
            sigma,
            n_simulations,
        }
    }

    fn simulate_paths(&self) -> Vec<Vec<f64>> {
        let dt = self.t / 365.0;
        let mut paths = vec![vec![0.0; 365]; self.n_simulations];
        for path in paths.iter_mut() {
            path[0] = self.s0;
        }
        for i in 1..365 {
            let mut rng = rand::thread_rng();
            let normal = Normal::new(0.0, 1.0).unwrap();
            for j in 0..self.n_simulations {
                let z = normal.sample(&mut rng);
                path[j][i] = path[j][i - 1] * ((self.r - 0.5 * self.sigma.powi(2)) * dt + self.sigma * (dt.sqrt()) * z).exp();
            }
        }
        paths
    }

    fn calculate_payoff(&self, paths: Vec<Vec<f64>>) -> Vec<f64> {
        paths.iter().map(|path| f64::max(path[364] - self.k, 0.0)).collect()
    }
}

struct OptionPricer {
    model: FinancialModel,
}

impl OptionPricer {
    fn new(model: FinancialModel) -> Self {
        OptionPricer { model }
    }

    fn price_option(&self) -> f64 {
        let paths = self.model.simulate_paths();
        let payoff = self.model.calculate_payoff(paths);
        let option_price = (-self.model.r * self.model.t).exp() * payoff.iter().sum::<f64>() / self.model.n_simulations as f64;
        option_price
    }
}

fn main() {
    let s0 = 100.0;
    let k = 100.0;
    let t = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let n_simulations = 10000;
    let model = FinancialModel::new(s0, k, t, r, sigma, n_simulations);
    let pricer = OptionPricer::new(model);
    let price = pricer.price_option();
    println!("{}", price);
}