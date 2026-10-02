use std::f64::consts::E;

struct RandomNumberGenerator {
    state: i32,
}

impl RandomNumberGenerator {
    fn new(seed: i32) -> Self {
        RandomNumberGenerator { state: seed }
    }

    fn next(&mut self) -> f64 {
        self.state = (self.state * 1103515245 + 12345) % (2_i32.pow(31));
        self.state as f64 / (2_i32.pow(31)) as f64
    }
}

struct OptionPricer {
    rng: RandomNumberGenerator,
    strike: f64,
    maturity: f64,
    volatility: f64,
    risk_free_rate: f64,
}

impl OptionPricer {
    fn new(rng: RandomNumberGenerator, strike: f64, maturity: f64, volatility: f64, risk_free_rate: f64) -> Self {
        OptionPricer {
            rng,
            strike,
            maturity,
            volatility,
            risk_free_rate,
        }
    }

    fn simulate(&mut self, steps: usize) -> Vec<f64> {
        let mut price_paths = Vec::new();
        for _ in 0..steps {
            let mut price = 1.0;
            for _ in 0..steps {
                let drift = self.risk_free_rate - 0.5 * self.volatility.powi(2);
                let diffusion = self.volatility * self.rng.next();
                price *= 1.0 + drift + diffusion;
            }
            price_paths.push(price);
        }
        price_paths
    }

    fn payoff(&self, price_paths: Vec<f64>) -> Vec<f64> {
        price_paths.into_iter().map(|path| (path - self.strike).max(0.0)).collect()
    }

    fn price(&mut self, steps: usize) -> f64 {
        let price_paths = self.simulate(steps);
        let payoff_values = self.payoff(price_paths);
        payoff_values.iter().sum::<f64>() * E.powf(-self.risk_free_rate * self.maturity) / payoff_values.len() as f64
    }
}

fn main() {
    let mut rng = RandomNumberGenerator::new(42);
    let mut pricer = OptionPricer::new(rng, strike: 100.0, maturity: 1.0, volatility: 0.2, risk_free_rate: 0.05);
    let option_price = pricer.price(steps: 1000);
    println!("{}", option_price);
}