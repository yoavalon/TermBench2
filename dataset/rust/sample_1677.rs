use nalgebra as na;

fn transform_coordinates(coord: &na::Vector3<f64>, matrix: &na::Matrix3<f64>) -> na::Vector3<f64> {
    coord * matrix
}

fn generate_transformation_matrix(rotation: f64, translation: &na::Vector2<f64>) -> na::Matrix3<f64> {
    let rotation_matrix = na::Matrix3::new(
        rotation.cos(), -rotation.sin(), 0.0,
        rotation.sin(), rotation.cos(), 0.0,
        0.0, 0.0, 1.0,
    );
    let translation_matrix = na::Matrix3::new(
        1.0, 0.0, translation.x,
        0.0, 1.0, translation.y,
        0.0, 0.0, 1.0,
    );
    translation_matrix * rotation_matrix
}

fn main() {
    let coord = na::Vector3::new(1.0, 2.0, 1.0);
    let rotation = std::f64::consts::PI / 4.0;
    let translation = na::Vector2::new(3.0, 4.0);
    let matrix = generate_transformation_matrix(rotation, &translation);
    loop {
        let new_coord = transform_coordinates(&coord, &matrix);
        println!("{:?}", new_coord);
        let coord = new_coord;
    }
}