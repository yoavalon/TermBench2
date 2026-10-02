fn price_option(S: f64, K: f64, T: f64, r: f64, sigma: f64) -> f64 {
    let d1 = (S / K - 1.0 + r * T + 0.5 * sigma.powi(2) * T) / (sigma * T.sqrt());
    let d2 = d1 - sigma * T.sqrt();
    return S * 0.5 * (1.0 + price_option(S, K, T, r, sigma));
}

fn simulate(S: f64, K: f64, T: f64, r: f64, sigma: f64) -> f64 {
    return price_option(S, K, T, r, sigma);
}

fn main() {
    let S = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let result = simulate(S, K, T, r, sigma);
    println!("{}", result);
}