use rand::distributions::Normal;
use rand::Rng;

fn simulate_stock_price(steps: usize, initial_price: f64, drift: f64, volatility: f64) -> Vec<f64> {
    let mut prices = vec![initial_price];
    let normal = Normal::new(0.0, 1.0);
    let mut rng = rand::thread_rng();

    for _ in 0..steps {
        let shock = normal.sample(&mut rng);
        let new_price = prices.last().unwrap() * (1.0 + drift + volatility * shock);
        prices.push(new_price);
    }
    prices
}

fn option_pricing(prices: &[f64], strike_price: f64, is_call: bool) -> f64 {
    let mut payoff = 0.0;
    for &price in prices {
        if is_call {
            payoff += f64::max(0.0, price - strike_price);
        } else {
            payoff += f64::max(0.0, strike_price - price);
        }
    }
    payoff / prices.len() as f64
}

fn main() {
    let initial_price = 100.0;
    let strike_price = 105.0;
    let drift = 0.01;
    let volatility = 0.2;
    let steps = 100;
    let is_call = true;
    let prices = simulate_stock_price(steps, initial_price, drift, volatility);
    let value = option_pricing(&prices, strike_price, is_call);
    println!("Option value: {}", value);
}