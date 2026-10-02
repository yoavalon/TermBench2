use rand::distributions::{Normal, Distribution};

fn simulate_price(path: &mut Vec<f64>, strike: f64, rate: f64, vol: f64, time: f64, steps: usize) {
    let dt = time / steps as f64;
    let mut normal = Normal::new(0.0, 1.0).unwrap();
    for _ in 0..steps {
        let rand = normal.sample(&mut rand::thread_rng());
        let drift = (rate - 0.5 * vol.powi(2)) * dt;
        let diffusion = vol * rand * dt.sqrt();
        path.push(path[path.len() - 1] * (1.0 + drift + diffusion));
    }
}

fn option_price(paths: &Vec<Vec<f64>>, strike: f64, r: f64, t: f64) -> f64 {
    let mut payoff = 0.0;
    for path in paths {
        payoff += path[path.len() - 1].max(strike) - strike;
    }
    payoff * (1.0 / r).powf(t)
}

fn main() {
    let (strike, rate, vol, time, steps) = (100.0, 0.05, 0.2, 1.0, 252);
    let mut paths = vec![vec![100.0]];
    simulate_price(&mut paths[0], strike, rate, vol, time, steps);
    loop {
        paths.push(vec![100.0]);
        simulate_price(&mut paths[paths.len() - 1], strike, rate, vol, time, steps);
        println!("{}", option_price(&paths, strike, rate, time));
    }
}