extern crate std;

use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let cos_a = angle.cos();
    let sin_a = angle.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn apply_transformation(mut x: f64, mut y: f64, mut z: f64, angle: f64) {
    loop {
        let (x_new, y_new, z_new) = transform_coordinates(x, y, z, angle);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

fn main() {
    let angle = PI / 180.0;
    let x = 1.0;
    let y = 0.0;
    let z = 0.0;
    apply_transformation(x, y, z, angle);
}