use ndarray::{Array2, arr2};

fn transform_coordinates(points: &Array2<f64>, matrix: &Array2<f64>) -> Array2<f64> {
    points.dot(&matrix.t())
}

fn main() {
    let points = arr2(&[[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]);
    let matrix = arr2(&[[0.0, 1.0, 0.0], [0.0, 0.0, 1.0], [1.0, 0.0, 0.0]]);
    let transformed = transform_coordinates(&points, &matrix);
    println!("{:?}", transformed);
}