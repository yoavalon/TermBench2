extern crate rand;

use rand::distributions::{Normal, Distribution};
use std::f64;

struct MonteCarlo {
    iterations: u32,
    option_type: String,
    strike: f64,
    underlying: f64,
    sigma: f64,
    r: f64,
    t: f64,
}

impl MonteCarlo {
    fn new(iterations: u32, option_type: String, strike: f64, underlying: f64, sigma: f64, r: f64, t: f64) -> Self {
        MonteCarlo {
            iterations,
            option_type,
            strike,
            underlying,
            sigma,
            r,
            t,
        }
    }

    fn price(&self) -> f64 {
        let mut total = 0.0;
        let normal = Normal::new(0.0, 1.0);

        for _ in 0..self.iterations {
            let price = self.underlying * f64::exp(self.r * self.t + self.sigma * f64::sqrt(self.t) * normal.sample(&mut rand::thread_rng()));
            let payoff = self.payoff(price);
            let discounted_payoff = payoff * f64::exp(-self.r * self.t);
            total += discounted_payoff;
        }
        total / (self.iterations as f64)
    }

    fn payoff(&self, price: f64) -> f64 {
        if self.option_type == "call" {
            f64::max(price - self.strike, 0.0)
        } else if self.option_type == "put" {
            f64::max(self.strike - price, 0.0)
        } else {
            0.0
        }
    }
}

struct Option {
    type_: String,
    strike: f64,
    underlying: f64,
    sigma: f64,
    r: f64,
    t: f64,
}

impl Option {
    fn new(type_: String, strike: f64, underlying: f64, sigma: f64, r: f64, t: f64) -> Self {
        Option {
            type_,
            strike,
            underlying,
            sigma,
            r,
            t,
        }
    }

    fn evaluate(&self) -> f64 {
        let model = MonteCarlo::new(10000, self.type_.clone(), self.strike, self.underlying, self.sigma, self.r, self.t);
        model.price()
    }
}

fn main() {
    let option = Option::new("call".to_string(), 100.0, 100.0, 0.2, 0.05, 1.0);
    let result = option.evaluate();
    println!("Option price: {}", result);
}