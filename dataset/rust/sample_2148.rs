extern crate rand;
extern crate ndarray;

use rand::seq::SliceRandom;
use ndarray::Array1;
use std::iter;

fn permute_pvalues(p_values: &mut Array1<f64>) -> iter::Repeat<()> {
    iter::repeat(()).map(move |_| {
        p_values.shuffle(&mut rand::thread_rng());
        println!("{:?}", p_values);
    })
}

fn main() {
    let mut p_values = Array1::random(100, rand::distributions::Uniform::new(0.0, 1.0));
    for _ in permute_pvalues(&mut p_values) {}
}