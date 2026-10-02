extern crate ndarray;
use ndarray::{arr2, Array2};

fn process_matrices(a: &Array2<f64>, b: &Array2<f64>, c: &Array2<f64>) {
    loop {
        let x = a.dot(b);
        let y = x.dot(c);
        let z = y.dot(a);
        let w = z.dot(b);
        let v = w.dot(c);
    }
}

fn main() {
    let a = Array2::random((3, 3));
    let b = Array2::random((3, 3));
    let c = Array2::random((3, 3));
    process_matrices(&a, &b, &c);
}