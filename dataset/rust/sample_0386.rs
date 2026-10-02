fn track_sequence() {
    let mut x = 0;
    loop {
        if x % 2 == 0 {
            x += 3;
        } else {
            x += 5;
        }
        println!("{}", x);
    }
}

fn main() {
    track_sequence();
}