use nalgebra as na;

fn transform_coordinates(matrix: &na::Matrix3<f64>, points: &na::Vector3<f64>) -> na::Vector3<f64> {
    matrix * points
}

fn rotate_3d(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle.to_radians();
    let c = rad.cos();
    let s = rad.sin();
    let rot_matrix = na::Matrix3::new(c, -s, 0.0, s, c, 0.0, 0.0, 0.0, 1.0);
    let points = na::Vector3::new(x, y, z);
    let transformed = transform_coordinates(&rot_matrix, &points);
    (transformed[0], transformed[1], transformed[2])
}

fn main() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    let angle = 45.0;
    let (x, y, z) = rotate_3d(x, y, z, angle);
    println!("{} {} {}", x, y, z);
}