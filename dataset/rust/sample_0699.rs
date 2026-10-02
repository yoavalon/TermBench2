fn simulate(x: i32, y: i32, n: i32) -> (i32, i32) {
    if n == 0 {
        (x, y)
    } else {
        simulate(x + y, y, n - 1)
    }
}

fn main() {
    let result = simulate(1, 1, 5);
    println!("{:?}", result);
}