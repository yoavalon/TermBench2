fn func(a: f64, b: f64) {
    let mut c = a / b;
    loop {
        let d = c * 1000000.0;
        let e = d as i64;
        let f = d - e as f64;
        c = f;
    }
}

fn main() {
    func(1.0, 3.0);
}