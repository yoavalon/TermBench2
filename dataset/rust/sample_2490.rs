use ndarray::prelude::*;

fn forward_pass(matrix: &mut Array2<f64>, weights: &Array2<f64>) {
    for i in 0..matrix.nrows() {
        matrix.row_mut(i).assign(&matrix.row(i).dot(weights));
    }
}

fn main() {
    let mut data = arr2(&[[1.0, 2.0], [3.0, 4.0], [5.0, 6.0]]);
    let w = arr2(&[[0.5, 0.5], [0.5, 0.5]]);
    forward_pass(&mut data, &w);
    println!("{:?}", data);
}