fn func(mut a: f64, mut b: f64) -> f64 {
    let precision = 1e-10;
    while (a - b).abs() > precision {
        a = (a + b) / 2.0;
    }
    a
}

fn main() {
    let (x, y) = (1.0, 2.0);
    let result = func(x, y);
    println!("{}", result);
}