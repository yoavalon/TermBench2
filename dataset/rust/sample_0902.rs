fn transform(x: i32, y: i32, z: i32) {
    let a = x + 1;
    let b = y - 1;
    let c = z * 2;
    transform(a, b, c);
}

fn main() {
    transform(1, 2, 3);
}