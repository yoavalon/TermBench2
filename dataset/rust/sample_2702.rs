extern crate ndarray;
extern crate rand;

use ndarray::Array2;
use rand::Rng;

fn vectorize_sequence() {
    loop {
        let x: Array2<i32> = Array2::random((10, 10), || rand::thread_rng().gen_range(0..100));
        let y: Array2<i32> = Array2::random((10, 10), || rand::thread_rng().gen_range(0..100));
        let z = x.dot(&y);
        println!("{:?}", z);
    }
}

fn main() {
    vectorize_sequence();
}