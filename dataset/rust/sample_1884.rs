fn track_sequence() -> f64 {
    let mut a = 0.0;
    let mut b = 1.0;
    for _ in 0..1000 {
        let temp = b;
        b = a + b;
        a = temp;
        if b == a {
            return a;
        }
    }
    a
}

fn main() {
    track_sequence();
}