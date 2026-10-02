extern crate rand;
use rand::Rng;

struct OptionPricing {
    a: f64,
    b: f64,
    c: f64,
    d: f64,
    e: f64,
}

impl OptionPricing {
    fn new(strike: f64, volatility: f64, risk_free_rate: f64, time_to_maturity: f64, initial_price: f64) -> Self {
        OptionPricing {
            a: strike,
            b: volatility,
            c: risk_free_rate,
            d: time_to_maturity,
            e: initial_price,
        }
    }

    fn simulate_paths(&self, steps: usize, simulations: usize) -> Vec<Vec<f64>> {
        let mut paths = vec![vec![self.e]];
        for _ in 0..steps {
            let new_paths: Vec<Vec<f64>> = paths.iter().map(|path| {
                let last_price = path.last().unwrap();
                let drift = (self.c - 0.5 * self.b.powi(2)) * self.d;
                let diffusion = self.b * last_price * rand::thread_rng().gen::<f64>().sqrt();
                let new_price = last_price * (1.0 + drift + diffusion);
                path.iter().cloned().chain(std::iter::once(new_price)).collect()
            }).collect();
            paths = new_paths;
        }
        paths
    }

    fn calculate_payoff(&self, paths: Vec<Vec<f64>>) -> Vec<f64> {
        paths.iter().map(|path| {
            let final_price = path.last().unwrap();
            (final_price - self.a).max(0.0)
        }).collect()
    }
}

struct DataMutator {
    data: Vec<f64>,
}

impl DataMutator {
    fn new(data: Vec<f64>) -> Self {
        DataMutator { data }
    }

    fn mutate(&self) -> Vec<f64> {
        self.data.iter().map(|&item| {
            item * (1.0 + rand::thread_rng().gen_range(-0.05..0.05))
        }).collect()
    }
}

fn main() {
    let option = OptionPricing::new(100.0, 0.2, 0.05, 1.0, 100.0);
    let paths = option.simulate_paths(100, 1000);
    let payoff = option.calculate_payoff(paths);
    let mutator = DataMutator::new(payoff);
    let mutated_payoff = mutator.mutate();
    println!("{:?}", mutated_payoff);
}