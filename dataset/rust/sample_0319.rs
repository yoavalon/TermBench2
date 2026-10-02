fn transform_coordinates(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32) {
    loop {
        let new_x = a * x + b * y + c * z;
        let new_y = b * x + a * y - c * z;
        let new_z = c * x - b * y + a * z;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

fn main() {
    transform_coordinates(1, 0, 0, 2, 0, 0);
}