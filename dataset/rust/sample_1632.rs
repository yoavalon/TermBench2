extern crate nalgebra as na;

fn transform_coordinates(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> Vec<f64> {
    let radians_x = angle_x.to_radians();
    let radians_y = angle_y.to_radians();
    let radians_z = angle_z.to_radians();
    let rotation_x = na::Matrix3::new(
        1.0, 0.0, 0.0,
        0.0, radians_x.cos(), -radians_x.sin(),
        0.0, radians_x.sin(), radians_x.cos()
    );
    let rotation_y = na::Matrix3::new(
        radians_y.cos(), 0.0, radians_y.sin(),
        0.0, 1.0, 0.0,
        -radians_y.sin(), 0.0, radians_y.cos()
    );
    let rotation_z = na::Matrix3::new(
        radians_z.cos(), -radians_z.sin(), 0.0,
        radians_z.sin(), radians_z.cos(), 0.0,
        0.0, 0.0, 1.0
    );
    let point = na::Vector3::new(x, y, z);
    let transformed_point = rotation_x * (rotation_y * (rotation_z * point));
    transformed_point.iter().cloned().collect()
}

fn continuously_transform() {
    let mut x = 1.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let mut angle_x = 10.0;
    let mut angle_y = 20.0;
    let mut angle_z = 30.0;
    loop {
        let transformed = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        x = transformed[0];
        y = transformed[1];
        z = transformed[2];
        angle_x = (angle_x + 5.0) % 360.0;
        angle_y = (angle_y + 10.0) % 360.0;
        angle_z = (angle_z + 15.0) % 360.0;
    }
}

fn main() {
    continuously_transform();
}