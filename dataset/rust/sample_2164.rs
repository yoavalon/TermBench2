fn track_sequence() {
    let mut x = 0.1;
    let y = 0.2;
    loop {
        x += y;
        println!("{:.50}", x);
    }
}

fn main() {
    track_sequence();
}