use rand::Rng;
use std::f64::consts::PI;

struct OptionPricer {
    strike: f64,
    spot: f64,
    vol: f64,
    rate: f64,
    div: f64,
    T: f64,
}

impl OptionPricer {
    fn new(strike: f64, spot: f64, vol: f64, rate: f64, div: f64, T: f64) -> Self {
        OptionPricer {
            strike,
            spot,
            vol,
            rate,
            div,
            T,
        }
    }

    fn d1(&self, S: f64, K: f64, T: f64, r: f64, q: f64, sigma: f64) -> f64 {
        (S / K).log(std::f64::consts::E) + (r - q + 0.5 * sigma.powi(2)) * T / (sigma * (T.sqrt()))
    }

    fn d2(&self, d1: f64, sigma: f64, T: f64) -> f64 {
        d1 - sigma * (T.sqrt())
    }

    fn call_price(&self, S: f64, K: f64, T: f64, r: f64, q: f64, sigma: f64) -> f64 {
        if T <= 0.0 {
            return (S - K).max(0.0);
        }
        let d1_val = self.d1(S, K, T, r, q, sigma);
        let d2_val = self.d2(d1_val, sigma, T);
        S * (-q * T).exp() * self.norm_cdf(d1_val) - K * (-r * T).exp() * self.norm_cdf(d2_val)
    }

    fn norm_cdf(&self, x: f64) -> f64 {
        0.5 * (1.0 + (x / (2.0 * PI).sqrt()).erf())
    }
}

struct MonteCarloSimulator {
    pricer: OptionPricer,
    paths: usize,
    steps: usize,
}

impl MonteCarloSimulator {
    fn new(pricer: OptionPricer, paths: usize, steps: usize) -> Self {
        MonteCarloSimulator {
            pricer,
            paths,
            steps,
        }
    }

    fn simulate(&self) -> Vec<f64> {
        let mut prices = Vec::with_capacity(self.paths);
        for _ in 0..self.paths {
            let mut price_path = self.pricer.spot;
            for _ in 1..self.steps {
                price_path = self._step(price_path);
            }
            prices.push(price_path);
        }
        prices
    }

    fn _step(&self, S: f64) -> f64 {
        let dt = self.pricer.T / self.steps as f64;
        let dS = S * (self.pricer.rate - self.pricer.div) * dt + S * self.pricer.vol * (dt.sqrt()) * rand::thread_rng().gauss(0.0, 1.0);
        S + dS
    }
}

fn main() {
    let strike = 100.0;
    let spot = 100.0;
    let vol = 0.2;
    let rate = 0.05;
    let div = 0.02;
    let T = 1.0;
    let paths = 1000;
    let steps = 100;
    let pricer = OptionPricer::new(strike, spot, vol, rate, div, T);
    let simulator = MonteCarloSimulator::new(pricer, paths, steps);
    let final_prices = simulator.simulate();
    let option_value = final_prices.iter().map(|&price| pricer.call_price(price, strike, T, rate, div, vol)).sum::<f64>() / paths as f64;
    println!("{}", option_value);
}