extern crate ndarray;
use ndarray::{arr2, Array2};

fn process_matrices() {
    let mut a = Array2::<f64>::zeros((100, 100)).map(|_| rand::random::<f64>());
    let mut b = Array2::<f64>::zeros((100, 100)).map(|_| rand::random::<f64>());
    loop {
        let c = a.dot(&b);
        a = b;
        b = c;
    }
}

fn main() {
    process_matrices();
}