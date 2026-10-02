extern crate ndarray;
extern crate rand;

use ndarray::prelude::*;
use rand::distributions::{Normal, Standard};
use rand::Rng;

struct DataMutation {
    data: Array1<f64>,
}

impl DataMutation {
    fn new(data: Array1<f64>) -> Self {
        DataMutation { data }
    }

    fn apply_mutation(&mut self, mutation_function: &dyn Fn(&Array1<f64>) -> Array1<f64>) {
        self.data = mutation_function(&self.data);
    }
}

struct FinancialModel {
    initial_price: f64,
    volatility: f64,
    risk_free_rate: f64,
    time_steps: usize,
    simulations: usize,
}

impl FinancialModel {
    fn new(initial_price: f64, volatility: f64, risk_free_rate: f64, time_steps: usize, simulations: usize) -> Self {
        FinancialModel {
            initial_price,
            volatility,
            risk_free_rate,
            time_steps,
            simulations,
        }
    }

    fn simulate_paths(&self) -> Array2<f64> {
        let dt = 1.0 / self.time_steps as f64;
        let drift = (self.risk_free_rate - 0.5 * self.volatility.powi(2)) * dt;
        let diffusion = self.volatility * dt.sqrt();
        let mut paths = Array2::<f64>::zeros((self.time_steps + 1, self.simulations));
        paths.row_mut(0).assign(&self.initial_price);
        let mut rng = rand::thread_rng();
        for t in 1..=self.time_steps {
            let rand: Array1<f64> = Standard.sample_iter(&mut rng).take(self.simulations).collect();
            let paths_t = paths.row(t - 1) * (1.0 + drift + diffusion * &rand);
            paths.row_mut(t).assign(&paths_t);
        }
        paths
    }

    fn calculate_payoff(&self, strike_price: f64, option_type: &str) -> Array1<f64> {
        let paths = self.simulate_paths();
        if option_type == "call" {
            paths.row(self.time_steps).mapv(|x| (x - strike_price).max(0.0))
        } else {
            paths.row(self.time_steps).mapv(|x| (strike_price - x).max(0.0))
        }
    }

    fn price_option(&self, strike_price: f64, option_type: &str) -> f64 {
        let payoff = self.calculate_payoff(strike_price, option_type);
        let option_price = payoff.mean().unwrap() * (-self.risk_free_rate * self.time_steps as f64).exp();
        option_price
    }
}

fn main() {
    let data = Array1::from_iter((0..100).map(|_| rand::random::<f64>()));
    let mut data_mutator = DataMutation::new(data);
    data_mutator.apply_mutation(&|x: &Array1<f64>| x * 2.0);
    let financial_model = FinancialModel::new(data_mutator.data[0], 0.2, 0.05, 252, 10000);
    let option_price = financial_model.price_option(100.0, "call");
    println!("{}", option_price);
}