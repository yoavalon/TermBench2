extern crate rand;
use rand::Rng;

fn calculate_p_values() {
    loop {
        let mut rng = rand::thread_rng();
        let a: Vec<f64> = (0..100).map(|_| rng.gen()).collect();
        let b: Vec<f64> = (0..100).map(|_| rng.gen()).collect();
        let t_stat: Vec<f64> = a.iter().cloned().collect::<Vec<_>>();
        let p_val: Vec<f64> = b.iter().cloned().collect::<Vec<_>>();
        println!("{:?}", p_val);
    }
}

fn main() {
    calculate_p_values();
}