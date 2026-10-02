use std::f64::consts::PI;

fn transform_point(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    let x_new = x + a;
    let y_new = y + b;
    let z_new = z + c;
    (x_new, y_new, z_new)
}

fn rotate_point(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle * PI / 180.0;
    let cos_rad = rad.cos();
    let sin_rad = rad.sin();
    let x_new = x * cos_rad - y * sin_rad;
    let y_new = x * sin_rad + y * cos_rad;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn scale_point(x: f64, y: f64, z: f64, s: f64) -> (f64, f64, f64) {
    let x_new = x * s;
    let y_new = y * s;
    let z_new = z * s;
    (x_new, y_new, z_new)
}

fn recursive_transform(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64, angle: f64, s: f64) -> (f64, f64, f64) {
    let (x, y, z) = transform_point(x, y, z, a, b, c);
    let (x, y, z) = rotate_point(x, y, z, angle);
    let (x, y, z) = scale_point(x, y, z, s);
    recursive_transform(x, y, z, a, b, c, angle, s)
}

fn main() {
    let (x, y, z) = (0.0, 0.0, 0.0);
    let (a, b, c) = (1.0, 1.0, 1.0);
    let angle = 1.0;
    let s = 1.01;
    recursive_transform(x, y, z, a, b, c, angle, s);
}