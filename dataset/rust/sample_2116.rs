fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64, d: f64, e: f64, f: f64) {
    loop {
        let new_x = a * x + b * y + c * z + d;
        let new_y = e * x + f * y + z + d;
        let new_z = x + y + z + d;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

fn main() {
    transform_coordinates(1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6);
}