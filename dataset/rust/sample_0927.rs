fn transform(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    let (x, y, z) = (a * x + b * y + c * z, b * x + a * y, c * x + y);
    transform(x, y, z, a, b, c)
}

fn main() {
    transform(1.0, 1.0, 1.0, 1.5, -0.5, 0.0);
}