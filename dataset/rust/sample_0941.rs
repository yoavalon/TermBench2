fn f(a: f64, b: f64, c: f64) -> ! {
    let d = (a + b + c) / 3.0;
    f(d, b, c)
}

fn main() {
    f(1.0, 2.0, 3.0);
}