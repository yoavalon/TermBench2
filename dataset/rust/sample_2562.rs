use nalgebra::{DMatrix, DVector};

fn transform_coordinates(coords: DVector<f64>, matrix: DMatrix<f64>) -> DVector<f64> {
    matrix * coords
}

fn generate_transformation_matrix(angle_x: f64, angle_y: f64, angle_z: f64) -> DMatrix<f64> {
    let Rx = DMatrix::from_row_slice(3, 3, &[1.0, 0.0, 0.0,
                                              0.0, angle_x.cos(), -angle_x.sin(),
                                              0.0, angle_x.sin(), angle_x.cos()]);
    let Ry = DMatrix::from_row_slice(3, 3, &[angle_y.cos(), 0.0, angle_y.sin(),
                                              0.0, 1.0, 0.0,
                                              -angle_y.sin(), 0.0, angle_y.cos()]);
    let Rz = DMatrix::from_row_slice(3, 3, &[angle_z.cos(), -angle_z.sin(), 0.0,
                                              angle_z.sin(), angle_z.cos(), 0.0,
                                              0.0, 0.0, 1.0]);
    Rx * Ry * Rz
}

fn main() {
    let coords = DVector::from_row_slice(&[1.0, 2.0, 3.0]);
    let angles = [std::f64::consts::PI / 4.0, std::f64::consts::PI / 3.0, std::f64::consts::PI / 6.0];
    let matrix = generate_transformation_matrix(angles[0], angles[1], angles[2]);
    let new_coords = transform_coordinates(coords, matrix);
    println!("{:?}", new_coords);
}