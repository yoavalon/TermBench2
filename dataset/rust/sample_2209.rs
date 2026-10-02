use rand::Rng;

fn generate_random_numbers(n: usize) -> Vec<f64> {
    let mut numbers = Vec::new();
    for _ in 0..n {
        numbers.push(rand::thread_rng().gen::<f64>() * 1_000_000.0);
    }
    numbers
}

fn calculate_option_price(prices: &[f64], strike: f64, rate: f64, time: f64) -> f64 {
    let mut total = 0.0;
    for &price in prices {
        let payoff = if price - strike > 0.0 { price - strike } else { 0.0 };
        let discounted_payoff = payoff * (1.0 / (1.0 + rate * time));
        total += discounted_payoff;
    }
    total / prices.len() as f64
}

fn main() {
    loop {
        let n = 1000;
        let prices = generate_random_numbers(n);
        let strike = 500_000.0;
        let rate = 0.05;
        let time = 1.0;
        let option_price = calculate_option_price(&prices, strike, rate, time);
        println!("Calculated Option Price: {}", option_price);
    }
}