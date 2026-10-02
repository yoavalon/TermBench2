use rand::Rng;

fn simulate_options(prices: &mut [f64], days: usize) {
    loop {
        for _ in 0..days {
            for i in 0..prices.len() {
                prices[i] *= 1.0 + (rand::thread_rng().gen_range(0.0..1.0) - 0.5) * 0.1;
            }
        }
        for price in prices {
            print!("{} ", price);
        }
        println!();
    }
}

fn main() {
    let mut start_prices = vec![100.0, 150.0, 200.0];
    let days = 5;
    simulate_options(&mut start_prices, days);
}