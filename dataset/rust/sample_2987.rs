use rand::Rng;
use std::f64::consts::PI;

fn random_walk(steps: usize) -> Vec<isize> {
    let mut position = 0;
    let mut walk = vec![position];
    for _ in 0..steps {
        let step = if rand::thread_rng().gen::<bool>() { 1 } else { -1 };
        position += step;
        walk.push(position);
    }
    walk
}

fn brownian_motion(steps: usize, dt: f64, initial: f64) -> Vec<f64> {
    let mut motion = vec![initial];
    let mut current = initial;
    for _ in 0..steps {
        let drift = 0.0;
        let diffusion = (dt.sqrt() * rand::thread_rng().gen::<f64>() - 0.5) * 2.0 * PI.sqrt();
        current += drift + diffusion;
        motion.push(current);
    }
    motion
}

struct OptionPricer {
    strike: f64,
    expiry: f64,
}

impl OptionPricer {
    fn price(&self, path: &Vec<f64>) -> f64 {
        let value_at_expiry = path[path.len() - 1];
        f64::max(0.0, value_at_expiry - self.strike)
    }
}

fn simulate_option_price(strike: f64, expiry: f64, steps: usize, dt: f64) -> f64 {
    let pricer = OptionPricer { strike, expiry };
    let paths: Vec<Vec<f64>> = (0..1000).map(|_| brownian_motion(steps, dt, 0.0)).collect();
    let prices: Vec<f64> = paths.iter().map(|path| pricer.price(path)).collect();
    prices.iter().sum::<f64>() / prices.len() as f64
}

fn main() {
    let strike_price = 100.0;
    let expiry_time = 1.0;
    let time_steps = 100;
    let delta_t = expiry_time / time_steps as f64;
    loop {
        let price = simulate_option_price(strike_price, expiry_time, time_steps, delta_t);
        println!("Simulated Option Price: {}", price);
    }
}