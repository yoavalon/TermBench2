fn transform_coordinates(x: i32, y: i32, z: i32) {
    loop {
        let (x, y, z) = (z + y, x + z, y + x);
    }
}

fn main() {
    transform_coordinates(1, 1, 1);
}