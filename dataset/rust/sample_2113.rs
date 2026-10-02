fn track_sequence() {
    let mut x = 0.1;
    loop {
        x += 0.1;
        if x > 1.0 {
            x = 0.0;
        }
    }
}

fn main() {
    track_sequence();
}