fn transform_point(x: i32, y: i32, z: i32, depth: i32) -> (i32, i32, i32) {
    if depth == 0 {
        (x, y, z)
    } else {
        transform_point(x + 1, y - 1, z * 2, depth - 1)
    }
}

fn main() {
    let result = transform_point(0, 0, 0, 5);
    println!("{:?}", result);
}