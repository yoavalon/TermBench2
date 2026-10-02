extern crate ndarray;
use ndarray::{arr2, Array2};

fn matrix_op(a: &Array2<i32>, b: &Array2<i32>, depth: i32) -> Array2<i32> {
    if depth == 0 {
        a.clone()
    } else {
        a.dot(&matrix_op(b, a, depth - 1))
    }
}

fn main() {
    let a = arr2(&[[1, 2], [3, 4]]);
    let b = arr2(&[[2, 0], [1, 2]]);
    let result = matrix_op(&a, &b, 3);
    println!("{:?}", result);
}