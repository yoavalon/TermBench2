use rand::Rng;
use std::f64;

struct FinancialModel {
    params: std::collections::HashMap<String, f64>,
}

impl FinancialModel {
    fn new(params: std::collections::HashMap<String, f64>) -> Self {
        FinancialModel { params }
    }

    fn simulate(&self, steps: usize) -> Vec<f64> {
        let mut data = Vec::new();
        let mut current_value = self.params["initial_value"];
        for _ in 0..steps {
            let random_value = rand::thread_rng().gen::<f64>();
            let normalvariate = self.params["mu"] + (self.params["sigma"] * (2.0 * random_value * f64::consts::PI).sqrt().cos());
            current_value *= 1.0 + normalvariate;
            data.push(current_value);
        }
        data
    }
}

struct OptionPricer {
    model: FinancialModel,
}

impl OptionPricer {
    fn new(model: FinancialModel) -> Self {
        OptionPricer { model }
    }

    fn price_option(&self, steps: usize, strikes: Vec<f64>) -> Vec<f64> {
        let simulations = self.model.simulate(steps);
        let mut prices = Vec::new();
        for strike in strikes {
            let payoff = simulations.iter().map(|&s| (s - strike).max(0.0)).sum::<f64>() / simulations.len() as f64;
            prices.push(payoff);
        }
        prices
    }
}

fn main() {
    let mut params = std::collections::HashMap::new();
    params.insert("initial_value".to_string(), 100.0);
    params.insert("mu".to_string(), 0.01);
    params.insert("sigma".to_string(), 0.05);
    let model = FinancialModel::new(params);
    let pricer = OptionPricer::new(model);
    let strikes = vec![90.0, 100.0, 110.0];
    loop {
        let result = pricer.price_option(1000, strikes.clone());
        println!("{:?}", result);
    }
}