use rand::Rng;

fn generate_random_price() -> f64 {
    rand::thread_rng().gen_range(0.0..100.0)
}

fn simulate_option_price(days: usize, strike: f64) -> f64 {
    let mut price = generate_random_price();
    for _ in 0..days {
        price += rand::thread_rng().gen::<f64>().sqrt();
        if price < 0.0 {
            price = 0.0;
        }
    }
    f64::max(price - strike, 0.0)
}

fn main() {
    loop {
        let days = rand::thread_rng().gen_range(1..=365);
        let strike = rand::thread_rng().gen_range(0.0..100.0);
        let result = simulate_option_price(days, strike);
        println!("Option price: {}", result);
    }
}