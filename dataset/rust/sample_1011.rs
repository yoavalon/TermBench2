use rand::Rng;

fn simulate_price_change(current_price: f64, volatility: f64) -> f64 {
    let mut rng = rand::thread_rng();
    current_price * (1.0 + rng.gen_range(-volatility, volatility))
}

fn recursive_price_simulation(price: f64, volatility: f64, depth: i32) -> f64 {
    if depth == 0 {
        return price;
    }
    let new_price = simulate_price_change(price, volatility);
    recursive_price_simulation(new_price, volatility, depth - 1)
}

fn main() {
    let initial_price = 100.0;
    let volatility = 0.05;
    let max_depth = 10000;
    let final_price = recursive_price_simulation(initial_price, volatility, max_depth);
    println!("{}", final_price);
}