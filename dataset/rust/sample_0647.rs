fn optimize(x: i32, y: i32, z: i32, n: i32) -> (i32, i32, i32) {
    if n == 0 {
        (x, y, z)
    } else {
        let a = x + 1;
        let b = y - 1;
        let c = z * 2;
        optimize(a, b, c, n - 1)
    }
}

fn main() {
    let result = optimize(1, 2, 3, 5);
    println!("{:?}", result);
}