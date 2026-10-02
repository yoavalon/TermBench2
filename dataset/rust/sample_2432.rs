use ndarray::{array, Array1, Array2};

fn process_matrix(x: Array1<f64>) -> Array1<f64> {
    let w = array![[0.2, 0.3], [0.4, 0.1]];
    let b = array![0.1, 0.2];
    let y = w.dot(&x) + &b;
    y
}

fn main() {
    let x = array![1.0, 2.0];
    let result = process_matrix(x);
    println!("{:?}", result);
}