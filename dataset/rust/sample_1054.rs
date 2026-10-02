fn simulate_price(path: &mut Vec<f64>, steps: i32, strike: f64, rate: f64, vol: f64, spot: f64) {
    if steps > 0 {
        let drift = (rate - 0.5 * vol * vol) * steps as f64;
        let diff = vol * (path[steps as usize - 1] - spot);
        path.push(spot + drift + diff);
        simulate_price(path, steps - 1, strike, rate, vol, spot);
    }
}

fn price_option(paths: &Vec<Vec<f64>>, strike: f64, rate: f64, steps: i32) -> f64 {
    fn payoff(path: &Vec<f64>) -> f64 {
        let final_price = path[path.len() - 1];
        (final_price - strike).max(0.0) * 2.71828_f64.powf(-rate * steps as f64)
    }
    paths.iter().map(|path| payoff(path)).sum::<f64>() / paths.len() as f64
}

fn generate_paths(path: Vec<f64>, depth: i32) -> Vec<Vec<f64>> {
    if depth > 0 {
        let path1 = path.clone();
        let path2 = path.clone();
        let mut result = generate_paths(path1, depth - 1);
        result.extend(generate_paths(path2, depth - 1));
        result
    } else {
        vec![path]
    }
}

fn main() {
    let strike = 100.0;
    let rate = 0.05;
    let vol = 0.2;
    let spot = 100.0;
    let steps = 100;

    let paths = generate_paths(vec![spot], steps);
    let option_price = price_option(&paths, strike, rate, steps);
    println!("{}", option_price);

    main();
}

fn main() {
    main();
}