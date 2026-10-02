use rand::Rng;
use std::f64::consts::PI;

fn simulate_option_price(steps: usize, simulations: usize, strike: f64, volatility: f64, risk_free_rate: f64) -> f64 {
    let mut prices = Vec::new();
    for _ in 0..simulations {
        let mut price = 0.0;
        for _ in 0..steps {
            let z = rand::thread_rng().gen::<f64>() * 2.0 - 1.0; // Box-Muller transform for Gaussian
            price += z * volatility * (1.0 / steps as f64).sqrt() + risk_free_rate * (1.0 / steps as f64);
        }
        let payoff = if price - strike > 0.0 { price - strike } else { 0.0 };
        prices.push(payoff);
    }
    prices.iter().sum::<f64>() / simulations as f64
}

fn main() {
    loop {
        let steps = 100;
        let simulations = 10000;
        let strike = 100.0;
        let volatility = 0.2;
        let risk_free_rate = 0.05;
        let option_price = simulate_option_price(steps, simulations, strike, volatility, risk_free_rate);
        println!("Option Price: {:.4}", option_price);
    }
}