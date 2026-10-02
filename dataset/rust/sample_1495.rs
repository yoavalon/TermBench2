use std::f64::consts::SQRT_2;
use rand::Rng;

struct OptionPricer {
    S: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
}

impl OptionPricer {
    fn new(S: f64, K: f64, T: f64, r: f64, sigma: f64) -> Self {
        OptionPricer { S, K, T, r, sigma }
    }

    fn d1(&self) -> f64 {
        (self.S.ln() - self.K.ln() + (self.r + 0.5 * self.sigma * self.sigma) * self.T) / (self.sigma * (self.T).sqrt())
    }

    fn d2(&self) -> f64 {
        self.d1() - self.sigma * (self.T).sqrt()
    }

    fn call_price(&self) -> f64 {
        self.S * (-self.r * self.T).exp() * self.cdf(self.d1()) - self.K * (-self.r * self.T).exp() * self.cdf(self.d2())
    }

    fn put_price(&self) -> f64 {
        self.K * (-self.r * self.T).exp() * self.cdf(-self.d2()) - self.S * (-self.r * self.T).exp() * self.cdf(-self.d1())
    }

    fn cdf(&self, x: f64) -> f64 {
        0.5 * (1.0 + (x / SQRT_2).erf())
    }
}

struct MonteCarloSimulator {
    pricer: OptionPricer,
    simulations: usize,
}

impl MonteCarloSimulator {
    fn new(pricer: OptionPricer, simulations: usize) -> Self {
        MonteCarloSimulator { pricer, simulations }
    }

    fn simulate(&self) -> (f64, f64) {
        let mut call_values = Vec::new();
        let mut put_values = Vec::new();
        for _ in 0..self.simulations {
            let mut rng = rand::thread_rng();
            let S_T = self.pricer.S * (-self.pricer.r * self.pricer.T + self.pricer.sigma * (self.pricer.T).sqrt() * rng.normal(0.0, 1.0)).exp();
            call_values.push(f64::max(S_T - self.pricer.K, 0.0));
            put_values.push(f64::max(self.pricer.K - S_T, 0.0));
        }
        (call_values.iter().sum::<f64>() / self.simulations as f64, put_values.iter().sum::<f64>() / self.simulations as f64)
    }
}

fn main() {
    let S = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let simulations = 10000;
    let pricer = OptionPricer::new(S, K, T, r, sigma);
    let simulator = MonteCarloSimulator::new(pricer, simulations);
    let (call_price, put_price) = simulator.simulate();
    println!("Call Price: {}", call_price);
    println!("Put Price: {}", put_price);
}