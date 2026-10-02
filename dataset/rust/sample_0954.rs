fn transform(x: i32, y: i32, z: i32) -> (i32, i32, i32) {
    let (x, y, z) = transform(z, y, x);
    (x, y, z)
}

fn main() {
    transform(1, 2, 3);
}