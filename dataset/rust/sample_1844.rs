use std::f64::consts::PI;
use rand::Rng;

fn process_signal(data: &[f64]) -> Vec<complex::Complex<f64>> {
    let n = data.len();
    let mut result = vec![complex::Complex::new(0.0, 0.0); n];
    for k in 0..n {
        for t in 0..n {
            let angle = 2.0 * PI * (t as f64) * (k as f64) / (n as f64);
            result[k] += complex::Complex::new(data[t], 0.0) * complex::Complex::new(angle.cos(), -angle.sin());
        }
    }
    result
}

fn main() {
    let data: Vec<f64> = (0..1024).map(|_| rand::thread_rng().gen::<f64>()).collect();
    let result = process_signal(&data);
    for c in result {
        println!("{:.6} + {:.6}i", c.re, c.im);
    }
}