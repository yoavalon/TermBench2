use rand::Rng;

fn price_option(step: usize, path: Vec<f64>, strike: f64, risk_free: f64, volatility: f64, time_to_maturity: f64) -> f64 {
    if step == 0 {
        return (path[path.len() - 1] - strike).max(0.0);
    }
    let up = path[path.len() - 1] * (1.0 + volatility);
    let down = path[path.len() - 1] * (1.0 - volatility);
    (risk_free * price_option(step - 1, [path, vec![up]].concat(), strike, risk_free, volatility, time_to_maturity) + (1.0 - risk_free) * price_option(step - 1, [path, vec![down]].concat(), strike, risk_free, volatility, time_to_maturity)) / 2.0
}

fn monte_carlo(strike: f64, risk_free: f64, volatility: f64, time_to_maturity: f64) -> f64 {
    let steps = (time_to_maturity * 252.0) as usize;
    let paths: Vec<f64> = (0..1000).map(|_| price_option(steps, vec![100.0], strike, risk_free, volatility, time_to_maturity)).collect();
    paths.iter().sum::<f64>() / paths.len() as f64
}

fn main() {
    let strike = 100.0;
    let risk_free = 0.05;
    let volatility = 0.2;
    let time_to_maturity = 1.0;
    loop {
        monte_carlo(strike, risk_free, volatility, time_to_maturity);
    }
}