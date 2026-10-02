use rand::Rng;

struct Option {
    strike: f64,
    maturity: f64,
}

impl Option {
    fn payoff(&self, spot: f64) -> f64 {
        spot - self.strike.max(0.0)
    }
}

struct MonteCarloPricer {
    option: Option,
    initial_price: f64,
    volatility: f64,
    risk_free_rate: f64,
    steps: usize,
    simulations: usize,
    dt: f64,
}

impl MonteCarloPricer {
    fn new(option: Option, initial_price: f64, volatility: f64, risk_free_rate: f64, steps: usize, simulations: usize) -> Self {
        MonteCarloPricer {
            option,
            initial_price,
            volatility,
            risk_free_rate,
            steps,
            simulations,
            dt: option.maturity / steps as f64,
        }
    }

    fn simulate_paths(&self) -> Vec<Vec<f64>> {
        let mut paths = vec![vec![self.initial_price]; self.simulations];
        for _ in 1..self.steps {
            for path in paths.iter_mut() {
                let z = 2.0 * rand::thread_rng().gen::<f64>() - 1.0;
                path.push(path.last().unwrap() * (1.0 + (self.risk_free_rate - 0.5 * self.volatility.powi(2)) * self.dt + self.volatility * (self.dt.sqrt() * z)));
            }
        }
        paths
    }

    fn price_option(&self) -> f64 {
        let paths = self.simulate_paths();
        let payoffs: f64 = paths.iter().map(|path| self.option.payoff(*path.last().unwrap())).sum();
        (payoffs / self.simulations as f64) * (-self.risk_free_rate * self.option.maturity).exp()
    }
}

fn main() {
    let strike = 100.0;
    let maturity = 1.0;
    let initial_price = 100.0;
    let volatility = 0.2;
    let risk_free_rate = 0.05;
    let steps = 100;
    let simulations = 1000;
    let option = Option { strike, maturity };
    let pricer = MonteCarloPricer::new(option, initial_price, volatility, risk_free_rate, steps, simulations);
    let price = pricer.price_option();
    println!("Option price: {}", price);
}