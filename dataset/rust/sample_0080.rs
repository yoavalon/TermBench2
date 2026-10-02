extern crate ndarray;

use ndarray::{arr2, Array2};

fn process_matrix(a: &Array2<i32>, b: &Array2<i32>) -> Array2<i32> {
    let c = a.dot(b);
    let d = c + c.t();
    d
}

fn main() {
    let a = arr2(&[[1, 2], [3, 4]]);
    let b = arr2(&[[2, 0], [1, 2]]);
    let result = process_matrix(&a, &b);
    println!("{:?}", result);
}