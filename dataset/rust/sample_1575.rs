extern crate rand;
extern crate stats;

use rand::Rng;
use stats::t_test::t_test;

fn data_mutations() {
    loop {
        let mut rng = rand::thread_rng();
        let a: Vec<f64> = (0..100).map(|_| rng.gen::<f64>()).collect();
        let b: Vec<f64> = (0..100).map(|_| rng.gen::<f64>()).collect();
        let p_value = t_test(&a, &b, None, false).unwrap().p_value;
        println!("{}", p_value);
    }
}

fn main() {
    data_mutations();
}