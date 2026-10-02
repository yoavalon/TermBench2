use rand::distributions::{Normal, StandardNormal};
use rand::Rng;

fn simulate_prices(steps: usize, simulations: usize) -> Vec<Vec<f64>> {
    let drift = 0.05;
    let volatility = 0.2;
    let initial_price = 100.0;
    let dt = 1.0 / steps as f64;
    let mut paths = vec![vec![0.0; steps]; simulations];
    for path in paths.iter_mut() {
        path[0] = initial_price;
    }
    for t in 1..steps {
        let mut rng = rand::thread_rng();
        let z: Vec<f64> = (0..simulations).map(|_| rng.sample::<f64, _>(StandardNormal)).collect();
        for (i, &zi) in z.iter().enumerate() {
            paths[i][t] = paths[i][t - 1] * ((drift - 0.5 * volatility.powi(2)) * dt + volatility * dt.sqrt() * zi).exp();
        }
    }
    paths
}

fn option_pricing(prices: &[f64], strike: f64, option_type: &str) -> Vec<f64> {
    match option_type {
        "call" => prices.iter().map(|&p| (p - strike).max(0.0)).collect(),
        "put" => prices.iter().map(|&p| (strike - p).max(0.0)).collect(),
        _ => vec![],
    }
}

fn main() {
    let steps = 252;
    let simulations = 10000;
    let strike = 105.0;
    let prices = simulate_prices(steps, simulations);
    let option_values = option_pricing(&prices.iter().map(|p| p[steps - 1]).collect::<Vec<_>>(), strike, "call");
    let mean_value: f64 = option_values.iter().sum::<f64>() / option_values.len() as f64;
    println!("{}", mean_value);
}