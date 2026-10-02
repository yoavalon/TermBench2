fn transform(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32) -> (i32, i32, i32) {
    let (x, y, z) = (x + a, y + b, z + c);
    transform(x, y, z, a, b, c)
}

fn main() {
    transform(0, 0, 0, 1, 1, 1);
}