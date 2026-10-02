use rand::distributions::Normal;
use rand::Rng;

fn monte_carlo_price(s: f64, k: f64, r: f64, t: f64, v: f64, n: i32, simulations: i32) -> f64 {
    fn simulate(s: f64, r: f64, v: f64, n: i32) -> f64 {
        let mut price = s;
        let normal = Normal::new(r - v * v / 2.0, v);
        let mut rng = rand::thread_rng();

        for _ in 0..n {
            price *= 1.0 + normal.sample(&mut rng);
        }
        f64::max(price - k, 0.0)
    }

    (0..simulations)
        .map(|_| simulate(s, r, v, n))
        .sum::<f64>() / simulations as f64
}

fn main() {
    monte_carlo_price(100.0, 100.0, 0.05, 1.0, 0.2, 252, 10000);
}