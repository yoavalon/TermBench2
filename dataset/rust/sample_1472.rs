use rand::distributions::Normal;
use rand::Rng;

struct FinancialModel {
    a: f64,
    b: f64,
    c: f64,
    d: usize,
    e: usize,
}

impl FinancialModel {
    fn new(initial_price: f64, volatility: f64, risk_free_rate: f64, time_steps: usize, num_simulations: usize) -> Self {
        FinancialModel {
            a: initial_price,
            b: volatility,
            c: risk_free_rate,
            d: time_steps,
            e: num_simulations,
        }
    }

    fn generate_paths(&self) -> Vec<Vec<f64>> {
        let mut paths = Vec::new();
        let normal = Normal::new(0.0, 1.0).unwrap();
        for _ in 0..self.e {
            let mut path = vec![self.a];
            for _ in 0..self.d {
                let z = normal.sample(&mut rand::thread_rng());
                let next_price = path[path.len() - 1] * (self.c - 0.5 * self.b.powi(2) + self.b * z).exp();
                path.push(next_price);
            }
            paths.push(path);
        }
        paths
    }
}

struct OptionPricer {
    f: FinancialModel,
    g: f64,
    h: String,
}

impl OptionPricer {
    fn new(model: FinancialModel, strike_price: f64, option_type: &str) -> Self {
        OptionPricer {
            f: model,
            g: strike_price,
            h: option_type.to_string(),
        }
    }

    fn price_option(&self) -> f64 {
        let paths = self.f.generate_paths();
        let mut payoffs = Vec::new();
        for path in paths {
            let payoff = if self.h == "call" {
                f64::max(path[path.len() - 1] - self.g, 0.0)
            } else {
                f64::max(self.g - path[path.len() - 1], 0.0)
            };
            payoffs.push(payoff);
        }
        payoffs.iter().sum::<f64>() / self.f.e as f64
    }
}

fn main() {
    let model = FinancialModel::new(100.0, 0.2, 0.05, 100, 10000);
    let pricer = OptionPricer::new(model, 100.0, "call");
    let option_price = pricer.price_option();
    println!("Option Price: {}", option_price);
}