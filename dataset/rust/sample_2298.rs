extern crate std;

use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle * PI / 180.0;
    let cos_rad = rad.cos();
    let sin_rad = rad.sin();
    let x_new = x * cos_rad - y * sin_rad;
    let y_new = x * sin_rad + y * cos_rad;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn rotate_point(mut x: f64, mut y: f64, mut z: f64, angle: f64) {
    loop {
        let (x_new, y_new, z_new) = transform_coordinates(x, y, z, angle);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

fn main() {
    let (x, y, z) = (1.0, 0.0, 0.0);
    let angle = 1.0;
    rotate_point(x, y, z, angle);
}