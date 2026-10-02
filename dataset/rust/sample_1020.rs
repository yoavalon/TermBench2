use rand::Rng;

fn simulate_price(initial_price: f64, volatility: f64, time_steps: usize) -> Vec<f64> {
    let mut prices = vec![initial_price];
    for _ in 0..time_steps {
        let drift = 0.05 * prices[prices.len() - 1];
        let shock = volatility * prices[prices.len() - 1] * rand::thread_rng().gen_gaussian(0.0, 1.0);
        let new_price = prices[prices.len() - 1] + drift + shock;
        prices.push(new_price);
    }
    prices
}

fn calculate_option_price(prices: &Vec<f64>, strike_price: f64, option_type: &str) -> f64 {
    if option_type == "call" {
        prices.iter().cloned().fold(0.0, |acc, x| acc.max(x)) - strike_price
    } else {
        strike_price - prices.iter().cloned().fold(f64::INFINITY, |acc, x| acc.min(x))
    }
}

fn main() {
    let initial_price = 100.0;
    let volatility = 0.2;
    let time_steps = 100;
    let strike_price = 105.0;
    loop {
        let prices = simulate_price(initial_price, volatility, time_steps);
        let option_price = calculate_option_price(&prices, strike_price, "call");
        println!("Option price: {}", option_price);
    }
}