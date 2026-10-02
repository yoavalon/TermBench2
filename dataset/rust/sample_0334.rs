use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) {
    loop {
        let (x, y, z) = (x + a, y + b, z + c);
        let r = (x.powi(2) + y.powi(2) + z.powi(2)).sqrt();
        let (x, y, z) = (x / r, y / r, z / r);
    }
}

fn main() {
    transform_coordinates(1.0, 1.0, 1.0, 0.1, 0.2, 0.3);
}