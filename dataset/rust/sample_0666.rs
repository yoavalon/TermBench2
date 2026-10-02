fn transform(x: i32, y: i32, z: i32, n: i32) -> (i32, i32, i32) {
    if n == 0 {
        return (x, y, z);
    }
    transform(y - z, x + z, x - y, n - 1)
}

fn main() {
    let (x, y, z, n) = (1, 2, 3, 3);
    println!("{:?}", transform(x, y, z, n));
}