use nalgebra::{Matrix3, Vector3};

fn transform_coordinates(coords: &Matrix3<f64>, matrix: &Matrix3<f64>) -> Matrix3<f64> {
    coords * matrix
}

fn generate_transformation_matrix(angle_x: f64, angle_y: f64, angle_z: f64) -> Matrix3<f64> {
    let c_x = angle_x.cos();
    let s_x = angle_x.sin();
    let c_y = angle_y.cos();
    let s_y = angle_y.sin();
    let c_z = angle_z.cos();
    let s_z = angle_z.sin();
    let rot_x = Matrix3::new(1.0, 0.0, 0.0, 0.0, c_x, -s_x, 0.0, s_x, c_x);
    let rot_y = Matrix3::new(c_y, 0.0, s_y, 0.0, 1.0, 0.0, -s_y, 0.0, c_y);
    let rot_z = Matrix3::new(c_z, -s_z, 0.0, s_z, c_z, 0.0, 0.0, 0.0, 1.0);
    rot_z * rot_y * rot_x
}

fn main() {
    let initial_coords = Matrix3::new(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    let angles = Vector3::new(45.0, 30.0, 60.0).map(|a| a.to_radians());
    let transformation_matrix = generate_transformation_matrix(angles[0], angles[1], angles[2]);
    let transformed_coords = transform_coordinates(&initial_coords, &transformation_matrix);
    println!("{:?}", transformed_coords);
}