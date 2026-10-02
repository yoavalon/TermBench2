extern crate nalgebra as na;

use na::{DMatrix, DVector, Vector3, Rotation3};

fn transform_matrix(rotation: &DMatrix<f64>, translation: &Vector3<f64>) -> DMatrix<f64> {
    let mut matrix = DMatrix::zeros(4, 4);
    matrix.block_mut(0, 0, 3, 3).copy_from(&rotation);
    matrix.block_mut(0, 3, 3, 1).copy_from(&translation);
    matrix[(3, 3)] = 1.0;
    matrix
}

fn apply_transformation(points: &DMatrix<f64>, matrix: &DMatrix<f64>) -> DMatrix<f64> {
    let homogeneous_points = points.clone().append_row(&DVector::from_element(points.ncols(), 1.0));
    let transformed_points = homogeneous_points * matrix.transpose();
    transformed_points.fixed_view::<3, 1>(0, 0, points.nrows(), points.ncols()).into()
}

fn generate_sequence(n: usize, initial_point: &Vector3<f64>, angle: f64, axis: &Vector3<f64>) -> Vec<Vector3<f64>> {
    let mut sequence = vec![initial_point.clone()];
    let mut rotation_matrix = Rotation3::identity();
    for _ in 0..n {
        rotation_matrix = rotation_matrix * Rotation3::from_axis_angle(&axis.normalize(), angle);
        let transformed_point = apply_transformation(&DMatrix::from_column(&sequence[sequence.len() - 1]), &rotation_matrix.to_homogeneous());
        sequence.push(transformed_point.row(0).into());
    }
    sequence
}

fn main() {
    let initial_point = Vector3::new(1.0, 0.0, 0.0);
    let angle = std::f64::consts::PI / 4.0;
    let axis = Vector3::new(0.0, 0.0, 1.0);
    let n = 10;
    let sequence = generate_sequence(n, &initial_point, angle, &axis);
    for point in sequence {
        println!("{:?}", point);
    }
}