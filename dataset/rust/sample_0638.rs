fn transform_3d(x: i32, y: i32, z: i32, n: i32) -> (i32, i32, i32) {
    if n == 0 {
        (x, y, z)
    } else {
        transform_3d(y, z, x, n - 1)
    }
}

fn main() {
    transform_3d(1, 2, 3, 5);
}