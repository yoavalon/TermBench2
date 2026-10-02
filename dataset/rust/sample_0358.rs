fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) {
    loop {
        let new_x = a * x + b * y + c * z;
        let new_y = a * y + b * z + c * x;
        let new_z = a * z + b * x + c * y;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

fn main() {
    transform_coordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5);
}