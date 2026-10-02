fn simulate_state(x: i32, y: i32, z: i32, n: i32) -> (i32, i32, i32) {
    if n == 0 {
        (x, y, z)
    } else {
        simulate_state(y, z, x + y + z, n - 1)
    }
}

fn main() {
    let (x, y, z, n) = (1, 1, 1, 5);
    let result = simulate_state(x, y, z, n);
    println!("{:?}", result);
}