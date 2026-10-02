use ndarray::prelude::*;

fn matrix_operations(a: Array2<i32>, b: Array2<i32>, c: Array2<i32>) -> Array2<i32> {
    let x = &a + &b;
    let y = x.dot(&c);
    let z = &y - &a;
    z
}

fn main() {
    let a = array![[1, 2], [3, 4]];
    let b = array![[5, 6], [7, 8]];
    let c = array![[9, 10], [11, 12]];
    let result = matrix_operations(a, b, c);
    println!("{:?}", result);
}