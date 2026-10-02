use rand::Rng;
use std::f64;

struct FinancialModel {
    S0: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
}

impl FinancialModel {
    fn new(S0: f64, K: f64, T: f64, r: f64, sigma: f64) -> Self {
        FinancialModel { S0, K, T, r, sigma }
    }

    fn simulate_paths(&self, num_simulations: usize, num_steps: usize) -> Vec<Vec<f64>> {
        let mut paths = Vec::with_capacity(num_simulations);
        let dt = self.T / num_steps as f64;
        let mut rng = rand::thread_rng();

        for _ in 0..num_simulations {
            let mut S = self.S0;
            let mut path = vec![S];
            for _ in 0..num_steps {
                let dS = S * (self.r * dt + self.sigma * (dt.sqrt() * rng.next_gaussian()));
                S += dS;
                path.push(S);
            }
            paths.push(path);
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

    fn european_call_price(&self, paths: Vec<Vec<f64>>) -> f64 {
        let mut payoff = 0.0;
        for path in paths {
            payoff += f64::max(path.last().unwrap() - self.model.K, 0.0);
        }
        payoff /= paths.len() as f64;
        let discount_factor = (-self.model.r * self.model.T).exp();
        payoff * discount_factor
    }
}

struct AnalysisEngine {
    pricer: OptionPricer,
}

impl AnalysisEngine {
    fn new(pricer: OptionPricer) -> Self {
        AnalysisEngine { pricer }
    }

    fn execute(&self, num_simulations: usize, num_steps: usize) -> f64 {
        let paths = self.pricer.model.simulate_paths(num_simulations, num_steps);
        self.pricer.european_call_price(paths)
    }
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let num_simulations = 1000;
    let num_steps = 100;
    let model = FinancialModel::new(S0, K, T, r, sigma);
    let pricer = OptionPricer::new(model);
    let engine = AnalysisEngine::new(pricer);
    let price = engine.execute(num_simulations, num_steps);
    println!("European Call Option Price: {}", price);
}