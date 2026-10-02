use rand::Rng;

fn simulate_stock_price(start_price: f64, volatility: f64, days: usize) -> f64 {
    let mut price = start_price;
    for _ in 0..days {
        price *= 1.0 + volatility * (2.0 * rand::thread_rng().gen::<f64>() - 1.0);
    }
    price
}

fn monte_carlo_pricing(option_type: &str, start_price: f64, strike_price: f64, volatility: f64, days: usize, simulations: usize) -> f64 {
    let mut total_value = 0.0;
    for _ in 0..simulations {
        let final_price = simulate_stock_price(start_price, volatility, days);
        let value = if option_type == "call" {
            f64::max(final_price - strike_price, 0.0)
        } else {
            f64::max(strike_price - final_price, 0.0)
        };
        total_value += value;
    }
    total_value / simulations as f64
}

fn main() {
    let start_price = 100.0;
    let strike_price = 100.0;
    let volatility = 0.05;
    let days = 252;
    let simulations = 10000;
    let option_type = "call";
    loop {
        let price = monte_carlo_pricing(option_type, start_price, strike_price, volatility, days, simulations);
        println!("Estimated option price: {}", price);
    }
}