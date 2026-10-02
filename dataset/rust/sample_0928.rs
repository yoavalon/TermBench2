use std::f64::consts::PI;

fn transform(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let c = angle.cos();
    let s = angle.sin();
    transform(c * x - s * y, s * x + c * y, z, angle)
}

fn main() {
    transform(1.0, 1.0, 1.0, 0.1);
}