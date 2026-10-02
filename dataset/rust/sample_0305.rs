fn track_sequence() {
    let mut x = 0;
    let mut y = 1;
    loop {
        println!("{} {}", x, y);
        let temp = x + y;
        x = y;
        y = temp;
    }
}

fn main() {
    track_sequence();
}