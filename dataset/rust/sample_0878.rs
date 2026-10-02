use rand::Rng;
use std::f64::consts::SQRT_2;

struct OptionPricing {
    S: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
}

impl OptionPricing {
    fn new(S: f64, K: f64, T: f64, r: f64, sigma: f64) -> Self {
        OptionPricing { S, K, T, r, sigma }
    }

    fn calculate_price(&self, n_simulations: usize, depth: usize) -> f64 {
        if depth == 0 {
            self.black_scholes(self.S, self.K, self.T, self.r, self.sigma)
        } else {
            self.monte_carlo(n_simulations, depth)
        }
    }

    fn black_scholes(&self, S: f64, K: f64, T: f64, r: f64, sigma: f64) -> f64 {
        let d1 = (S / K).ln() + (r + 0.5 * sigma * sigma) * T / (sigma * (T.sqrt()));
        let d2 = d1 - sigma * (T.sqrt());
        S * (-r * T).exp() * self.norm_cdf(d1) - K * (-r * T).exp() * self.norm_cdf(d2)
    }

    fn norm_cdf(&self, x: f64) -> f64 {
        0.5 * (1.0 + (x / SQRT_2).erf())
    }

    fn monte_carlo(&self, n_simulations: usize, depth: usize) -> f64 {
        let mut payoff_sum = 0.0;
        for _ in 0..n_simulations {
            let price_path = self.price_path_simulation();
            payoff_sum += price_path.last().unwrap().max(&0.0);
        }
        payoff_sum / n_simulations as f64 * (-self.r * self.T).exp()
    }

    fn price_path_simulation(&self) -> Vec<f64> {
        let mut path = vec![self.S];
        for _ in 0..(self.T as usize) {
            let drift = self.r * path.last().unwrap() * (1.0 / 252.0);
            let diffusion = path.last().unwrap() * self.sigma * (1.0 / 252.0).sqrt() * rand::thread_rng().gen::<f64>().sqrt();
            path.push(path.last().unwrap() + drift + diffusion);
        }
        path
    }
}

fn main() {
    let S = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let n_simulations = 1000;
    let depth = 2;
    let pricing_model = OptionPricing::new(S, K, T, r, sigma);
    let option_price = pricing_model.calculate_price(n_simulations, depth);
    println!("Option Price: {}", option_price);
}