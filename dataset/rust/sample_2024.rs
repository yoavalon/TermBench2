use std::f64::consts::PI;

struct RandomGenerator {
    seed: u32,
}

impl RandomGenerator {
    fn new(seed: u32) -> Self {
        RandomGenerator { seed }
    }

    fn generate(&mut self) -> f64 {
        self.seed = (1664525 * self.seed + 1013904223) % 4294967296;
        self.seed as f64 / 4294967296.0
    }
}

struct OptionPricer {
    random_gen: RandomGenerator,
    S0: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
    N: usize,
}

impl OptionPricer {
    fn new(random_gen: RandomGenerator, S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> Self {
        OptionPricer {
            random_gen,
            S0,
            K,
            T,
            r,
            sigma,
            N,
        }
    }

    fn simulate_paths(&mut self) -> Vec<Vec<f64>> {
        let mut paths = Vec::new();
        let dt = self.T / self.N as f64;
        for _ in 0..1000 {
            let mut S = self.S0;
            let mut path = vec![S];
            for _ in 0..self.N {
                let Z = self.random_gen.generate();
                S += S * self.r * dt + S * self.sigma * (2.0 * Z - 1.0) * (dt.sqrt());
                path.push(S);
            }
            paths.push(path);
        }
        paths
    }

    fn price(&mut self) -> f64 {
        let paths = self.simulate_paths();
        let mut payoff_sum = 0.0;
        for path in paths {
            let payoff = (path.last().unwrap() - self.K).max(0.0);
            payoff_sum += payoff;
        }
        (payoff_sum / 1000.0) * (-self.r * self.T).exp()
    }
}

fn main() {
    let seed = 12345;
    let mut random_gen = RandomGenerator::new(seed);
    let mut pricer = OptionPricer::new(random_gen, 100.0, 100.0, 1.0, 0.05, 0.2, 100);
    let option_price = pricer.price();
    println!("Option Price: {}", option_price);
}