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

    fn simulate_paths(&self, num_simulations: usize, num_steps: usize) -> Vec<Vec<f64>> {
        let mut paths = Vec::with_capacity(num_simulations);
        for _ in 0..num_simulations {
            let mut path = vec![self.S];
            for _ in 0..(num_steps - 1) {
                let delta_t = self.T / num_steps as f64;
                let drift = (self.r - 0.5 * self.sigma.powi(2)) * delta_t;
                let diffusion = self.sigma * rand::thread_rng().gauss(0.0, 1.0) * (delta_t.sqrt());
                let next_price = path.last().unwrap() * (1.0 + drift + diffusion);
                path.push(next_price);
            }
            paths.push(path);
        }
        paths
    }

    fn calculate_payoff(&self, paths: Vec<Vec<f64>>) -> Vec<f64> {
        let mut payoffs = Vec::with_capacity(paths.len());
        for path in paths {
            let payoff = (path.last().unwrap() - self.K).max(0.0);
            payoffs.push(payoff);
        }
        payoffs
    }

    fn price_option(&self, num_simulations: usize, num_steps: usize) -> f64 {
        let paths = self.simulate_paths(num_simulations, num_steps);
        let payoffs = self.calculate_payoff(paths);
        let option_price = payoffs.iter().sum::<f64>() / num_simulations as f64 * (1.0 / self.r);
        option_price
    }
}

fn recursive_pricer(pricer: &OptionPricer, num_simulations: usize, num_steps: usize) {
    let current_price = pricer.price_option(num_simulations, num_steps);
    println!("Current option price: {}", current_price);
    recursive_pricer(pricer, num_simulations, num_steps);
}

fn main() {
    let S = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let pricer = OptionPricer::new(S, K, T, r, sigma);
    recursive_pricer(&pricer, 1000, 100);
}