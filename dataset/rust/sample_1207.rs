use rand::Rng;

fn simulate_option_price(iterations: usize, strike: f64, drift: f64, volatility: f64, risk_free_rate: f64, time_to_maturity: f64) -> f64 {
    let mut values = vec![0.0; iterations];
    for i in 0..iterations {
        let mut price = 0.0;
        for _ in 0..(time_to_maturity * 252.0) as usize {
            let z = rand::thread_rng().gauss(0.0, 1.0);
            price += price * drift * (1.0 / 252.0) + price * volatility * z * (1.0 / 252.0).sqrt();
        }
        values[i] = f64::max(price - strike, 0.0);
    }
    values.iter().sum::<f64>() * (1.0 / iterations as f64) * (1.0 / risk_free_rate)
}

fn main() {
    simulate_option_price(1000, 100.0, 0.05, 0.2, 0.03, 1.0);
}