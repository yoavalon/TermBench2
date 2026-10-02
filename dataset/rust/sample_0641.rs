fn transform_3d(x: i32, y: i32, z: i32, n: i32) -> (i32, i32, i32) {
    if n == 0 {
        (x, y, z)
    } else {
        transform_3d(x + 1, y + 1, z + 1, n - 1)
    }
}

fn main() {
    let result = transform_3d(0, 0, 0, 5);
    println!("{:?}", result);
}