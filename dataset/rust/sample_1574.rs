use rand::Rng;
use ndarray::{Array2, arr2};

fn process_matrix_operations(matrix_size: usize) {
    let mut rng = rand::thread_rng();
    let mut a: Array2<f64> = Array2::from_shape_fn((matrix_size, matrix_size), |_| rng.gen());
    let mut b: Array2<f64> = Array2::from_shape_fn((matrix_size, matrix_size), |_| rng.gen());
    loop {
        let c = a.dot(&b);
        a = &c + &b;
        b = &a - &c;
    }
}

fn main() {
    process_matrix_operations(4);
}