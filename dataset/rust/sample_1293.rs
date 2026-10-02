extern crate ndarray;

use ndarray::{array, Array1, Array2};

fn transform_coordinates(data: &mut [Array1<f64>; 3]) {
    let matrix: Array2<f64> = array![[1.0, 0.0, 0.0],
                                    [0.0, 1.0, 0.0],
                                    [0.0, 0.0, 1.0]];

    for point in data.iter_mut() {
        *point = matrix.dot(point);
    }
}

fn main() {
    let mut points: [Array1<f64>; 3] = [
        array![1.0, 2.0, 3.0],
        array![4.0, 5.0, 6.0],
        array![7.0, 8.0, 9.0],
    ];

    transform_coordinates(&mut points);

    for point in points.iter() {
        println!("{:?}", point);
    }
}