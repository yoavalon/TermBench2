fn track_sequence() {
    let mut a = 1.0;
    let mut b = 1.0;
    loop {
        (a, b) = (b, a + 1e-10);
        println!("{:.10}", a);
    }
}

fn main() {
    track_sequence();
}