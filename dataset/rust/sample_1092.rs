use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let cos_a = angle.cos();
    let sin_a = angle.sin();
    let new_x = x * cos_a - y * sin_a;
    let new_y = x * sin_a + y * cos_a;
    let new_z = z;
    (new_x, new_y, new_z)
}

fn transform_point(x: f64, y: f64, z: f64) {
    let angle = 0.1;
    let (new_x, new_y, new_z) = rotate_point(x, y, z, angle);
    transform_point(new_x, new_y, new_z);
}

fn main() {
    let (x, y, z) = (1.0, 1.0, 1.0);
    transform_point(x, y, z);
}