use rand::Rng;
use std::f64;

struct OptionPricer {
    S0: Vec<f64>,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
    N: usize,
}

impl OptionPricer {
    fn new(S0: Vec<f64>, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> Self {
        OptionPricer { S0, K, T, r, sigma, N }
    }

    fn simulate_paths(&self) -> Vec<Vec<f64>> {
        let dt = self.T / self.N as f64;
        let mut paths = vec![self.S0.clone()];
        for _ in 1..=self.N {
            let mut z = vec![0.0; self.S0.len()];
            for zi in z.iter_mut() {
                *zi = rand::thread_rng().gen::<f64>();
            }
            let new_path: Vec<f64> = paths.last().unwrap().iter().zip(z.iter())
                .map(|(&s, &zi)| s * f64::exp((self.r - 0.5 * self.sigma.powi(2)) * dt + self.sigma * dt.sqrt() * (zi * 2.0 - 1.0)))
                .collect();
            paths.push(new_path);
        }
        paths
    }

    fn calculate_payoff(&self, paths: &Vec<Vec<f64>>) -> Vec<f64> {
        paths.last().unwrap().iter().map(|&s| (s - self.K).max(0.0)).collect()
    }
}

struct MonteCarloEngine {
    pricer: OptionPricer,
    num_simulations: usize,
}

impl MonteCarloEngine {
    fn new(pricer: OptionPricer, num_simulations: usize) -> Self {
        MonteCarloEngine { pricer, num_simulations }
    }

    fn run(&self) -> f64 {
        let mut payoffs = vec![0.0; self.num_simulations];
        for i in 0..self.num_simulations {
            let paths = self.pricer.simulate_paths();
            payoffs[i] = self.pricer.calculate_payoff(&paths).iter().sum::<f64>() / self.pricer.S0.len() as f64;
        }
        f64::exp(-self.pricer.r * self.pricer.T) * payoffs.iter().sum::<f64>() / self.num_simulations as f64
    }
}

fn main() {
    let S0 = vec![100.0];
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 252;
    let num_simulations = 10000;
    let pricer = OptionPricer::new(S0, K, T, r, sigma, N);
    let engine = MonteCarloEngine::new(pricer, num_simulations);
    let option_price = engine.run();
    println!("Option Price: {}", option_price);
}