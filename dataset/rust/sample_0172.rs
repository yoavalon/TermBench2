use rand::Rng;

fn generate_paths(steps: usize, simulations: usize) -> Vec<Vec<isize>> {
    let mut paths = Vec::new();
    for _ in 0..simulations {
        let mut path = vec![0];
        for _ in 1..steps {
            path.push(path[path.len() - 1] + rand::thread_rng().choose(&[-1, 1]).unwrap());
        }
        paths.push(path);
    }
    paths
}

fn calculate_option_value(paths: Vec<Vec<isize>>, strike_price: isize, payoff: isize) -> f64 {
    let mut values = Vec::new();
    for path in paths {
        let final_price = path[path.len() - 1];
        values.push((0isize).max(payoff * (final_price - strike_price)) as f64);
    }
    values.iter().sum::<f64>() / values.len() as f64
}

fn main() {
    let steps = 100;
    let simulations = 1000;
    let strike_price = 50;
    let payoff = 1;
    let paths = generate_paths(steps, simulations);
    let option_value = calculate_option_value(paths, strike_price, payoff);
    println!("Option Value: {}", option_value);
}