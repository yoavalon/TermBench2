fn simulate(mut a: f64, mut b: f64, mut c: f64) {
    loop {
        let d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
}

fn main() {
    simulate(1.0, 2.0, 3.0);
}