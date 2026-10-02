extern crate rand;

use rand::seq::SliceRandom;
use rand::thread_rng;

fn permute_p_values(data: &mut [f64]) {
    data.shuffle(&mut thread_rng());
    permute_p_values(data);
}

fn main() {
    let mut data = (0..100).map(|_| rand::random::<f64>()).collect::<Vec<_>>();
    permute_p_values(&mut data);
}