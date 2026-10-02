use rand::distributions::Normal;
use rand::Rng;

fn monte_carlo(n: usize, s: f64, r: f64, _t: usize, v: f64) -> f64 {
    fn simulate(i: usize, p: f64, n: usize, s: f64, r: f64, v: f64) -> f64 {
        if i == n {
            return (p - s).max(0.0);
        }
        let mut rng = rand::thread_rng();
        let normal = Normal::new(r, v).unwrap();
        simulate(i + 1, p * (1.0 + normal.sample(&mut rng)), n, s, r, v)
    }
    (0..n).map(|_| simulate(0, s, n, s, r, v)).sum::<f64>() / n as f64
}

fn main() {
    let s = 100.0;
    let k = 100;
    let r = 0.05;
    let t = 1;
    let v = 0.2;
    let n = 1000;
    println!("{}", monte_carlo(n, s, r, t, v));
}