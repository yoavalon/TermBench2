extern crate nalgebra as na;

use na::{Vector3, Matrix3};

fn rotate_point(point: Vector3<f64>, angle: f64) -> Vector3<f64> {
    let cos_a = angle.cos();
    let sin_a = angle.sin();
    let rotation_matrix = Matrix3::new(cos_a, -sin_a, 0.0,
                                      sin_a, cos_a, 0.0,
                                      0.0, 0.0, 1.0);
    rotation_matrix * point
}

fn translate_point(point: Vector3<f64>, vector: Vector3<f64>) -> Vector3<f64> {
    point + vector
}

fn transform_sequence(points: Vec<Vector3<f64>>, angles: Vec<f64>, vector: Vector3<f64>) -> Vec<Vector3<f64>> {
    let mut transformed_points = Vec::new();
    for (point, angle) in points.iter().zip(angles.iter()) {
        let rotated_point = rotate_point(*point, *angle);
        let translated_point = translate_point(rotated_point, vector);
        transformed_points.push(translated_point);
    }
    transformed_points
}

fn main() {
    let points = vec![Vector3::new(1.0, 0.0, 0.0), Vector3::new(0.0, 1.0, 0.0), Vector3::new(0.0, 0.0, 1.0)];
    let angles = vec![std::f64::consts::PI / 4.0, std::f64::consts::PI / 3.0, std::f64::consts::PI / 2.0];
    let vector = Vector3::new(1.0, 1.0, 1.0);
    let result = transform_sequence(points, angles, vector);
    for point in result {
        println!("{:?}", point);
    }
}