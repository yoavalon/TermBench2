use rand::distributions::{Normal, Distribution};

fn price_option(s: f64, k: f64, t: f64, r: f64, v: f64) -> f64 {
    if t == 0.0 {
        return f64::max(0.0, s - k);
    }
    let dt = 0.1;
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0);
    let u = 1.0 + r * dt + v * normal.sample(&mut rng) * (dt as f64).sqrt();
    let d = 1.0 + r * dt - v * normal.sample(&mut rng) * (dt as f64).sqrt();
    let p = (1.0 - r * dt) / (u - d);
    let pu = price_option(s * u, k, t - dt, r, v);
    let pd = price_option(s * d, k, t - dt, r, v);
    p * pu + (1.0 - p) * pd
}

fn main() {
    loop {
        price_option(100.0, 100.0, 1.0, 0.05, 0.2);
    }
}