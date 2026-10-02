use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

struct FinancialModel {
    S0: f64,
    sigma: f64,
    r: f64,
    K: f64,
    T: f64,
}

impl FinancialModel {
    fn new(initial_price: f64, volatility: f64, risk_free_rate: f64, strike_price: f64, maturity: f64) -> Self {
        FinancialModel {
            S0: initial_price,
            sigma: volatility,
            r: risk_free_rate,
            K: strike_price,
            T: maturity,
        }
    }

    fn simulate_paths(&self, num_paths: usize, num_steps: usize) -> Vec<Vec<f64>> {
        let dt = self.T / num_steps as f64;
        let mut paths = vec![vec![self.S0]; num_paths];
        for _ in 0..num_steps {
            let mut rng = thread_rng();
            let normal = Normal::new(0.0, 1.0);
            for i in 0..num_paths {
                let Z = normal.sample(&mut rng);
                let S_next = paths[i][paths[i].len() - 1] * ((self.r - 0.5 * self.sigma.powi(2)) * dt + self.sigma * dt.sqrt() * Z).exp();
                paths[i].push(S_next);
            }
        }
        paths
    }
}

struct OptionPricing {
    model: FinancialModel,
    num_paths: usize,
    num_steps: usize,
}

impl OptionPricing {
    fn new(model: FinancialModel, num_paths: usize, num_steps: usize) -> Self {
        OptionPricing {
            model,
            num_paths,
            num_steps,
        }
    }

    fn calculate_option_value(&self) -> f64 {
        let paths = self.model.simulate_paths(self.num_paths, self.num_steps);
        let mut option_values = Vec::new();
        for path in paths {
            let payoff = path[path.len() - 1].max(self.model.K) - self.model.K;
            option_values.push(payoff);
        }
        option_values.iter().sum::<f64>() / self.num_paths as f64 * (-self.model.r * self.model.T).exp()
    }
}

fn main() {
    let initial_price = 100.0;
    let volatility = 0.2;
    let risk_free_rate = 0.05;
    let strike_price = 100.0;
    let maturity = 1.0;
    let num_paths = 1000;
    let num_steps = 100;
    let model = FinancialModel::new(initial_price, volatility, risk_free_rate, strike_price, maturity);
    let option_pricing = OptionPricing::new(model, num_paths, num_steps);
    let value = option_pricing.calculate_option_value();
    println!("Option Value: {}", value);
}