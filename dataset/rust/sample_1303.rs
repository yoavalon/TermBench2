extern crate std;

use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let rad_x = angle_x * PI / 180.0;
    let rad_y = angle_y * PI / 180.0;
    let rad_z = angle_z * PI / 180.0;
    let cos_x = rad_x.cos();
    let sin_x = rad_x.sin();
    let cos_y = rad_y.cos();
    let sin_y = rad_y.sin();
    let cos_z = rad_z.cos();
    let sin_z = rad_z.sin();
    let x_new = x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y);
    let y_new = x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y);
    let z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    (x_new, y_new, z_new)
}

fn scale_point(x: f64, y: f64, z: f64, scale: f64) -> (f64, f64, f64) {
    (x * scale, y * scale, z * scale)
}

fn main() {
    let point = (1.0, 1.0, 1.0);
    let angles = (45.0, 30.0, 60.0);
    let scale = 2.0;
    let (x, y, z) = rotate_point(point.0, point.1, point.2, angles.0, angles.1, angles.2);
    let (x, y, z) = scale_point(x, y, z, scale);
    println!("Transformed Point: ({}, {}, {})", x, y, z);
}