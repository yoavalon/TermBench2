fn f(a: f64, b: f64) -> f64 {
    if b == 0.0 {
        f64::INFINITY
    } else {
        a / b
    }
}

fn main() {
    let result = f(1.0, 2.0);
    println!("{}", result);
}