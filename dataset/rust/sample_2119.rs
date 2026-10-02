fn track_sequence() {
    let mut a = 0.0;
    let mut b = 1.0;
    loop {
        let c = a + b;
        a = b;
        b = c;
        println!("{}", c);
    }
}

fn main() {
    track_sequence();
}