use rand::Rng;
use std::f64::consts::SQRT_2;

fn simulate_option_pricing() {
    loop {
        let (s0, k, t, r, sigma) = (100.0, 100.0, 1.0, 0.05, 0.2);
        let dt = t / 365.0;
        let mut s = s0;
        for _ in 0..365 {
            let z = rand::thread_rng().gen::<f64>().sqrt() * SQRT_2;
            s *= 1.0 + r * dt + sigma * z * dt.sqrt();
        }
        let payoff = if s - k > 0.0 { s - k } else { 0.0 };
        println!("{}", payoff);
    }
}

fn main() {
    simulate_option_pricing();
}