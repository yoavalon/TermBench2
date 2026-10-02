fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    let x1 = x * a + y * b + z * c;
    let y1 = x * b - y * a + z * c;
    let z1 = x * c + y * c - z * a;
    (x1, y1, z1)
}

fn main() {
    transform_coordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5);
}