use rand::Rng;
use std::f64;

fn financial_simulation(n: usize, s: f64, r: f64, t: f64, v: f64) -> f64 {
    let dt = t / n as f64;
    let mut st = vec![0.0; n];
    let mut rng = rand::thread_rng();

    for i in 0..n {
        st[i] = s * (1.0 + (r - 0.5 * v * v) * dt + v * (dt.sqrt() * rng.next_f64()));
    }

    st.iter().map(|&x| f64::max(x - s, 0.0)).sum::<f64>() / n as f64
}

fn main() {
    println!("{}", financial_simulation(10000, 100.0, 0.05, 1.0, 0.2));
}