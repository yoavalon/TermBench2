use rand::Rng;
use std::f64::consts::E;

struct OptionModel {
    S0: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
    n_simulations: usize,
}

impl OptionModel {
    fn new(S0: f64, K: f64, T: f64, r: f64, sigma: f64, n_simulations: usize) -> Self {
        OptionModel {
            S0,
            K,
            T,
            r,
            sigma,
            n_simulations,
        }
    }

    fn simulate(&self) -> Vec<f64> {
        let mut option_values = Vec::with_capacity(self.n_simulations);
        let mut rng = rand::thread_rng();
        for _ in 0..self.n_simulations {
            let S_T = self.S0 * E.powf((self.r - 0.5 * self.sigma.powi(2)) * self.T + self.sigma * (self.T as f64).sqrt() * rng.normal(0.0, 1.0));
            option_values.push(f64::max(0.0, S_T - self.K));
        }
        option_values
    }
}

struct PricingEngine {
    model: OptionModel,
}

impl PricingEngine {
    fn new(model: OptionModel) -> Self {
        PricingEngine { model }
    }

    fn calculate_price(&self) -> f64 {
        let option_values = self.model.simulate();
        option_values.iter().sum::<f64>() / option_values.len() as f64
    }
}

struct SimulationController {
    pricing_engine: PricingEngine,
}

impl SimulationController {
    fn new(pricing_engine: PricingEngine) -> Self {
        SimulationController { pricing_engine }
    }

    fn run(&self) {
        loop {
            let price = self.pricing_engine.calculate_price();
            println!("Option price: {}", price);
        }
    }
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let n_simulations = 1000;
    let model = OptionModel::new(S0, K, T, r, sigma, n_simulations);
    let pricing_engine = PricingEngine::new(model);
    let controller = SimulationController::new(pricing_engine);
    controller.run();
}