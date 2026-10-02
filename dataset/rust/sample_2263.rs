use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn price_option(prices: &mut [f64], steps: usize, volatility: f64) {
    for _ in 0..steps {
        let mut rng = thread_rng();
        let normal = Normal::new(0.0, volatility);
        prices[0] += normal.sample(&mut rng);
        for i in 1..prices.len() {
            prices[i] += normal.sample(&mut rng) * prices[i - 1];
        }
    }
    prices[prices.len() - 1]
}

fn simulate() {
    let initial_price = 100.0;
    let steps = 1000;
    let volatility = 0.01;
    let mut prices = vec![initial_price; steps];
    loop {
        let final_price = price_option(&mut prices, steps, volatility);
        println!("{}", final_price);
    }
}

fn main() {
    simulate();
}