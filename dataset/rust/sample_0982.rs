fn transform_coordinates(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32) {
    transform_coordinates(x + a, y + b, z + c, a, b, c);
}

fn main() {
    transform_coordinates(0, 0, 0, 1, 1, 1);
}