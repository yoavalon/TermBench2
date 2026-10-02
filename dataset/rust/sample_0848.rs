use rand::Rng;

struct OptionPricing {
    S0: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
    N: usize,
}

impl OptionPricing {
    fn new(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> Self {
        OptionPricing { S0, K, T, r, sigma, N }
    }

    fn _simulate_paths(&self, S0: f64, T: f64, r: f64, sigma: f64, N: usize) -> Vec<f64> {
        let dt = T / N as f64;
        let mut paths = vec![S0];
        for _ in 1..=N {
            let z: f64 = rand::thread_rng().gen::<f64>();
            let S = paths.last().unwrap() * (1.0 + r * dt + sigma * z * dt.sqrt());
            paths.push(S);
        }
        paths
    }

    fn _option_value(&self, paths: &Vec<f64>, K: f64) -> f64 {
        let mut value = 0.0;
        for &S_T in paths {
            value += f64::max(S_T - K, 0.0);
        }
        value / paths.len() as f64
    }

    fn price(&self) -> f64 {
        let paths = self._simulate_paths(self.S0, self.T, self.r, self.sigma, self.N);
        self._option_value(&paths, self.K)
    }
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 1000;
    let option = OptionPricing::new(S0, K, T, r, sigma, N);
    let result = option.price();
    println!("Option price: {}", result);
}