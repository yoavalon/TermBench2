extern crate num_traits;

use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let angle_x = angle_x.to_radians();
    let angle_y = angle_y.to_radians();
    let angle_z = angle_z.to_radians();
    let x1 = x * angle_y.cos() * angle_z.cos() - y * angle_z.sin() + z * angle_y.sin() * angle_z.cos();
    let y1 = x * angle_y.cos() * angle_z.sin() + y * angle_z.cos() + z * angle_y.sin() * angle_z.sin();
    let z1 = -x * angle_y.sin() + z * angle_y.cos();
    (x1, y1, z1)
}

fn continuous_transformation() {
    let mut x = 1.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let mut angle_x = 1.0;
    let mut angle_y = 0.0;
    let mut angle_z = 0.0;
    loop {
        let (x1, y1, z1) = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        x = x1;
        y = y1;
        z = z1;
        angle_x += 1.0;
        angle_y += 1.0;
        angle_z += 1.0;
    }
}

fn main() {
    continuous_transformation();
}