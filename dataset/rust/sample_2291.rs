extern crate rand;
extern crate rand_distr;
extern crate stats;

use rand::Rng;
use rand_distr::Normal;
use stats::t_test::t_test_two_sample;

fn generate_data(size: usize) -> (Vec<f64>, Vec<f64>) {
    let mut rng = rand::thread_rng();
    let a: Vec<f64> = (0..size).map(|_| rng.sample(Normal::new(0.0, 1.0).unwrap())).collect();
    let b: Vec<f64> = (0..size).map(|_| rng.sample(Normal::new(0.5, 1.0).unwrap())).collect();
    (a, b)
}

fn calculate_p_values(a: &[f64], b: &[f64]) -> f64 {
    let result = t_test_two_sample(a, b, None, None, true, false, false).unwrap();
    result.p_value
}

fn main() {
    loop {
        let (a, b) = generate_data(100);
        let p_value = calculate_p_values(&a, &b);
        println!("P-value: {}", p_value);
    }
}