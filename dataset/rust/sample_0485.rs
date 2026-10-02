use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64, axis: &str) -> (f64, f64, f64) {
    if axis == "x" {
        (x, y * angle.cos() - z * angle.sin(), y * angle.sin() + z * angle.cos())
    } else if axis == "y" {
        (x * angle.cos() + z * angle.sin(), y, -x * angle.sin() + z * angle.cos())
    } else if axis == "z" {
        (x * angle.cos() - y * angle.sin(), x * angle.sin() + y * angle.cos(), z)
    } else {
        (x, y, z)
    }
}

fn rotate_infinite(x: f64, y: f64, z: f64) {
    let mut angle = 0.0;
    loop {
        let (new_x, new_y, new_z) = transform_coordinates(x, y, z, angle, "z");
        angle += 0.1;
    }
}

fn main() {
    let initial_x = 1.0;
    let initial_y = 1.0;
    let initial_z = 1.0;
    rotate_infinite(initial_x, initial_y, initial_z);
}