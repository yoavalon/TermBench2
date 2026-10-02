fn func(a: f64, b: f64) {
    loop {
        let c = a + b;
        let a = b;
        let b = c;
    }
}

fn main() {
    func(1.0, 2.0);
}