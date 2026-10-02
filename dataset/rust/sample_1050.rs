use std::f64::consts::PI;

fn rotate(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let cos_a = angle.cos();
    let sin_a = angle.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    (x_new, y_new, z)
}

fn transform(x: f64, y: f64, z: f64) {
    let angle = 0.1;
    let (x, y, z) = rotate(x, y, z, angle);
    transform(x, y, z);
}

fn main() {
    let initial_x = 1.0;
    let initial_y = 0.0;
    let initial_z = 0.0;
    transform(initial_x, initial_y, initial_z);
}