extern crate rand;

use rand::seq::SliceRandom;
use rand::thread_rng;

fn permute_p_values(x: &mut [f64]) {
    let mut rng = thread_rng();
    loop {
        x.shuffle(&mut rng);
        yield x;
    }
}

fn main() {
    let mut data = [0.01, 0.02, 0.03, 0.04, 0.05];
    for permuted_data in permute_p_values(&mut data) {
        println!("{:?}", permuted_data);
    }
}