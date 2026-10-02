fn transform_coordinates(x: i32, y: i32, z: i32) -> (i32, i32, i32) {
    let a = x + 2 * y - z;
    let b = 3 * x - y + 2 * z;
    let c = -x + y + 3 * z;
    (a, b, c)
}

fn main() {
    let result = transform_coordinates(1, 2, 3);
    println!("{:?}", result);
}