extern crate rand;

use rand::distributions::{Normal, Distribution};

fn monte_carlo_option_pricing(s: f64, x: f64, t: f64, r: f64, v: f64, n: usize) -> f64 {
    let dt = t / n as f64;
    let mut st = vec![0.0; n + 1];
    st[0] = s;
    let normal = Normal::new(0.0, 1.0);

    for i in 1..=n {
        st[i] = st[i - 1] * (r - 0.5 * v * v) * dt + v * dt.sqrt() * normal.sample(&mut rand::thread_rng());
    }

    st.iter().map(|&st| (st - x).max(0.0)).sum::<f64>() * (-r * t).exp() / st.len() as f64
}

fn main() {
    let result = monte_carlo_option_pricing(100.0, 100.0, 1.0, 0.05, 0.2, 1000);
    println!("{}", result);
}