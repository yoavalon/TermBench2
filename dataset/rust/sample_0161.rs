use rand::distributions::{Normal, Distribution};

fn simulate_stock_price(steps: usize, initial_price: f64, drift: f64, volatility: f64) -> f64 {
    let mut price = initial_price;
    let normal = Normal::new(0.0, 1.0);
    for _ in 0..steps {
        let random_value = normal.sample(&mut rand::thread_rng());
        price += price * (drift + volatility * random_value);
    }
    price
}

fn price_option(pricing_function: fn(usize, f64, f64, f64) -> f64, initial_price: f64, strike_price: f64, steps: usize, drift: f64, volatility: f64, simulations: usize) -> f64 {
    let mut total = 0.0;
    for _ in 0..simulations {
        let final_price = pricing_function(steps, initial_price, drift, volatility);
        let payoff = f64::max(final_price - strike_price, 0.0);
        total += payoff;
    }
    total / simulations as f64
}

fn main() {
    let initial_price = 100.0;
    let strike_price = 100.0;
    let steps = 100;
    let drift = 0.0001;
    let volatility = 0.01;
    let simulations = 10000;
    let option_price = price_option(simulate_stock_price, initial_price, strike_price, steps, drift, volatility, simulations);
    println!("Option Price: {}", option_price);
}