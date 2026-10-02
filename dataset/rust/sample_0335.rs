fn transform_coordinates(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32) {
    let mut x = x;
    let mut y = y;
    let mut z = z;
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
    transform_coordinates(1, 0, 0, 1, 1, 0);
}