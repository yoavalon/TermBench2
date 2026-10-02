fn func(x: f64, n: u32) -> f64 {
    if n == 0 {
        1.0
    } else {
        x * func(x, n - 1)
    }
}

fn main() {
    let result = func(2.0, 10);
    println!("{}", result);
}