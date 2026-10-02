use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn monte_carlo_pricing(s: f64, k: f64, r: f64, v: f64, t: f64, n: usize) -> f64 {
    let dt = t / n as f64;
    let mut st = vec![0.0; n + 1];
    st[0] = s;
    let normal = Normal::new(0.0, 1.0);
    let mut rng = thread_rng();

    for i in 1..=n {
        st[i] = st[i - 1] * ((r - 0.5 * v * v) * dt + v * (dt.sqrt() * normal.sample(&mut rng))).exp();
    }

    (-r * t).exp() * st.iter().skip(n).cloned().map(|x| x.max(k)).sum::<f64>() / n as f64
}

fn main() {
    monte_carlo_pricing(100.0, 100.0, 0.05, 0.2, 1.0, 1000);
}