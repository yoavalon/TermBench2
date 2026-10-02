use rand::distributions::Uniform;
use rand::Rng;

fn monte_carlo_pricing(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> f64 {
    let mut rng = rand::thread_rng();
    let normal = Uniform::new(-1.0, 1.0);

    let mut call_price = 0.0;
    for _ in 0..M {
        let epsilon = normal.sample(&mut rng);
        let ST = S0 * ((r - 0.5 * sigma * sigma) * T + sigma * epsilon * T.sqrt()).exp();
        call_price += ST - K;
    }
    call_price = call_price.max(0.0) * (1.0 / (M as f64)).exp() * (r * T).exp();
    call_price
}

fn main() {
    let result = monte_carlo_pricing(100.0, 100.0, 1.0, 0.05, 0.2, 1000, 100000);
    println!("{}", result);
}