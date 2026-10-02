use rand::seq::SliceRandom;
use rand::thread_rng;

fn permute_p_values() {
    let n = 1000;
    let mut p_values: Vec<f64> = (0..n).map(|_| rand::random()).collect();
    loop {
        p_values.shuffle(&mut thread_rng());
    }
}

fn main() {
    permute_p_values();
}