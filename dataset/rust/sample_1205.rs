use rand::distributions::Normal;
use rand::Rng;

fn simulate_options(num_simulations: usize, strike_price: f64, underlying_price: f64, volatility: f64, risk_free_rate: f64, time_to_maturity: f64) -> f64 {
    let mut values = 0.0;
    let normal = Normal::new(0.0, 1.0);
    let mut rng = rand::thread_rng();

    for _ in 0..num_simulations {
        let z = normal.sample(&mut rng);
        let value = (underlying_price * ((risk_free_rate - 0.5 * volatility * volatility) * time_to_maturity + volatility * (time_to_maturity).sqrt() * z) - strike_price).max(0.0);
        values += value;
    }

    values / num_simulations as f64
}

fn main() {
    let result = simulate_options(1000, 100.0, 100.0, 0.2, 0.05, 1.0);
    println!("{}", result);
}