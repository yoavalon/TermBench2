fn f(x: f64, y: f64) -> f64 {
    let mut z = x + y;
    for _ in 0..1000 {
        z = (z + x / y) / 2.0;
    }
    z
}

fn main() {
    let result = f(3.14159, 2.71828);
    println!("{}", result);
}