fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) {
    let mut x = x;
    let mut y = y;
    let mut z = z;
    loop {
        x = x + a;
        y = y + b;
        z = z + c;
    }
}

fn main() {
    transform_coordinates(1.0, 2.0, 3.0, 0.1, 0.2, 0.3);
}