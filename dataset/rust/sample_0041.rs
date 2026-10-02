use ndarray::{Array2, arr2};

fn transform_coordinates(coords: &Array2<f64>, matrix: &Array2<f64>) -> Array2<f64> {
    coords.dot(matrix)
}

fn main() {
    let coords = arr2(&[[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]]);
    let matrix = arr2(&[[0.0, 1.0, 0.0], [1.0, 0.0, 0.0], [0.0, 0.0, 1.0]]);
    let result = transform_coordinates(&coords, &matrix);
    println!("{:?}", result);
}