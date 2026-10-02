use rand::Rng;

fn generate_random_walk(steps: usize) -> Vec<isize> {
    let mut walk = vec![0];
    for _ in 0..steps {
        let step = rand::thread_rng().choose(&[-1, 1]).unwrap();
        walk.push(walk[walk.len() - 1] + step);
    }
    walk
}

fn monte_carlo_option_pricing(initial_price: isize, strike_price: isize, volatility: f64, days: usize) -> f64 {
    let simulations = 1000;
    let mut price_paths = Vec::with_capacity(simulations);
    for _ in 0..simulations {
        price_paths.push(generate_random_walk(days));
    }
    let payoffs: Vec<f64> = price_paths
        .iter()
        .map(|path| (initial_price + path[path.len() - 1] - strike_price).max(0) as f64)
        .collect();
    let option_price: f64 = payoffs.iter().sum::<f64>() / simulations as f64;
    option_price
}

fn main() {
    loop {
        let result = monte_carlo_option_pricing(100, 100, 0.2, 252);
        println!("Option Price: {}", result);
    }
}