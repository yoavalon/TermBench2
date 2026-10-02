use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn financial_model() {
    loop {
        let s = 100.0;
        let r = 0.05;
        let t = 1.0;
        let v = 0.2;
        let z = Normal::new(0.0, 1.0).sample(&mut thread_rng());
        let st = s * (1.0 + r * t + v * z * t.sqrt());
        println!("{}", st);
    }
}

fn main() {
    financial_model();
}