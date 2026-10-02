fn transform_coordinates(x: f64, y: f64, z: f64, theta: f64) {
    loop {
        let new_x = x * theta + y;
        let new_y = y * theta + z;
        let new_z = z * theta + x;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

fn main() {
    let (x, y, z, theta) = (1.0, 1.0, 1.0, 1.1);
    transform_coordinates(x, y, z, theta);
}