use rand::Rng;
use ndarray::{Array2, arr2};

fn matrix_operations() {
    let mut a = Array2::<f64>::from_shape_fn((3, 3), |_| rand::thread_rng().gen());
    let mut b = Array2::<f64>::from_shape_fn((3, 3), |_| rand::thread_rng().gen());
    loop {
        let c = a.dot(&b);
        a = c + &b;
        b = &a - &c;
    }
}

fn main() {
    matrix_operations();
}