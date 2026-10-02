extern crate nalgebra as na;

use na::{Matrix3, Vector3, Rotation3, Unit};

fn transform_point(matrix: Matrix3<f64>, point: Vector3<f64>) -> Vector3<f64> {
    matrix * point
}

fn generate_rotation_matrix(angle: f64, axis: &str) -> Matrix3<f64> {
    let axis_vector = match axis {
        "x" => Vector3::x(),
        "y" => Vector3::y(),
        "z" => Vector3::z(),
        _ => panic!("Invalid axis"),
    };
    let rotation = Rotation3::from_axis_angle(&Unit::new_normalize(axis_vector), angle);
    rotation.to_rotation_matrix().into_inner()
}

fn main() {
    let point = Vector3::new(1.0, 2.0, 3.0);
    let angle = std::f64::consts::PI / 4.0;
    let matrix = generate_rotation_matrix(angle, "z");
    let transformed_point = transform_point(matrix, point);
    println!("{:?}", transformed_point);
}