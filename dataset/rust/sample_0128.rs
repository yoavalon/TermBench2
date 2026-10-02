extern crate rand;

use rand::Rng;

fn simulate_option_price(steps: usize, drift: f64, volatility: f64, initial_price: f64) -> f64 {
    let mut price = initial_price;
    for _ in 0..steps {
        let rand_val: f64 = rand::thread_rng().gauss(0.0, 1.0);
        price *= 1.0 + drift + volatility * rand_val;
    }
    price
}

fn is_terminating(price: f64, strike_price: f64, call_put: &str) -> bool {
    if call_put == "call" {
        price > strike_price
    } else if call_put == "put" {
        price < strike_price
    } else {
        false
    }
}

fn main() {
    let initial_price = 100.0;
    let strike_price = 105.0;
    let drift = 0.01;
    let volatility = 0.2;
    let steps = 100;
    let call_put = "call";
    let price = simulate_option_price(steps, drift, volatility, initial_price);
    let result = is_terminating(price, strike_price, call_put);
    println!("{}", result);
}