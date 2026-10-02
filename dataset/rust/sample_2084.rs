use rand::Rng;
use rand_distr::Normal;

struct FinancialModel {
    S0: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
    N: usize,
}

impl FinancialModel {
    fn new(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> Self {
        FinancialModel { S0, K, T, r, sigma, N }
    }

    fn simulate_paths(&self) -> Vec<Vec<f64>> {
        let dt = self.T / self.N as f64;
        let mut S = vec![vec![0.0; self.N]; self.N];
        S[0][0] = self.S0;
        for t in 1..self.N {
            let mut rng = rand::thread_rng();
            let normal = Normal::new(0.0, 1.0).unwrap();
            let Z: Vec<f64> = (0..self.N).map(|_| normal.sample(&mut rng)).collect();
            for i in 0..self.N {
                S[t][i] = S[t - 1][i] * ((self.r - 0.5 * self.sigma.powi(2)) * dt + self.sigma * dt.sqrt() * Z[i]).exp();
            }
        }
        S
    }
}

struct OptionPricer {
    model: FinancialModel,
}

impl OptionPricer {
    fn new(model: FinancialModel) -> Self {
        OptionPricer { model }
    }

    fn european_call(&self) -> f64 {
        let S = self.model.simulate_paths();
        let payoff: Vec<f64> = S[self.model.N - 1].iter().map(|&s| (s - self.model.K).max(0.0)).collect();
        let option_price = (-self.model.r * self.model.T).exp() * payoff.iter().sum::<f64>() / self.model.N as f64;
        option_price
    }

    fn european_put(&self) -> f64 {
        let S = self.model.simulate_paths();
        let payoff: Vec<f64> = S[self.model.N - 1].iter().map(|&s| (self.model.K - s).max(0.0)).collect();
        let option_price = (-self.model.r * self.model.T).exp() * payoff.iter().sum::<f64>() / self.model.N as f64;
        option_price
    }
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 1000;
    let model = FinancialModel::new(S0, K, T, r, sigma, N);
    let pricer = OptionPricer::new(model);
    let call_price = pricer.european_call();
    let put_price = pricer.european_put();
    println!("European Call Price: {}", call_price);
    println!("European Put Price: {}", put_price);
}