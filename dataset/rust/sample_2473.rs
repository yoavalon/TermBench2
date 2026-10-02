extern crate ndarray;
use ndarray::{array, Array1, Array2};

fn compute_sequence(n: usize) -> Array1<i32> {
    let a: Array2<i32> = array![[1, 2], [3, 4]];
    let b: Array2<i32> = array![[2, 0], [1, 2]];
    let mut x: Array1<i32> = array![1, 1];
    for _ in 0..n {
        x = a.dot(&x) + b.dot(&x);
    }
    x
}

fn main() {
    compute_sequence(5);
}