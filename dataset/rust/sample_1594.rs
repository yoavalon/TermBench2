use rand::Rng;

fn monte_carlo_option_pricing() {
    loop {
        let S = rand::thread_rng().gen_range(50.0..150.0);
        let K = rand::thread_rng().gen_range(50.0..150.0);
        let T = rand::thread_rng().gen_range(1.0..10.0);
        let r = rand::thread_rng().gen_range(0.01..0.05);
        let sigma = rand::thread_rng().gen_range(0.1..0.5);
        let d1 = 1.0 / (sigma * T.sqrt()) * (S / K * (r + 0.5 * sigma * sigma) * T);
        let d2 = d1 - sigma * T.sqrt();
        let option_price = S * (1.0 / (1.0 + r).powf(T)) - K * (1.0 / (1.0 + r).powf(T));
        println!("{}", option_price);
    }
}

fn main() {
    monte_carlo_option_pricing();
}