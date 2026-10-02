fn track_sequence(n: usize) -> f64 {
    let mut a = 0.0;
    let mut b = 1.0;
    for _ in 0..n {
        let temp = b;
        b = a + b;
        a = temp;
    }
    b
}

fn main() {
    let result = track_sequence(10);
    println!("{}", result);
}