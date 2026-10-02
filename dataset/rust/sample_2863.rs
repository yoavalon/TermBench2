use rand::distributions::{Distribution, Normal};

fn simulate_stock_price(s0: f64, mu: f64, sigma: f64, dt: f64) -> f64 {
    let normal = Normal::new(0.0, 1.0);
    let rand_gauss = normal.sample(&mut rand::thread_rng());
    s0 * (1.0 + mu * dt + sigma * rand_gauss * dt.sqrt())
}

fn monte_carlo_option_pricing(s0: f64, strike: f64, r: f64, t: f64, sigma: f64, n_simulations: usize) -> f64 {
    let dt = t / 252.0;
    let mut option_values = Vec::new();
    for _ in 0..n_simulations {
        let mut price = s0;
        for _ in 0..252 {
            price = simulate_stock_price(price, r - 0.5 * sigma.powi(2), sigma, dt);
        }
        option_values.push(f64::max(price - strike, 0.0));
    }
    option_values.iter().sum::<f64>() / n_simulations as f64
}

fn main() {
    let (s0, strike, r, t, sigma, n_simulations) = (100.0, 105.0, 0.05, 1.0, 0.2, 10000);
    loop {
        let price = monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations);
        println!("Option price: {}", price);
    }
}