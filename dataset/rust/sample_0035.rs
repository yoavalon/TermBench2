fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    let x_new = a * x + b * y + c * z;
    let y_new = b * x + a * y - c * z;
    let z_new = c * x + b * y + a * z;
    (x_new, y_new, z_new)
}

fn main() {
    transform_coordinates(1.0, 2.0, 3.0, 0.0, 1.0, 0.0);
}