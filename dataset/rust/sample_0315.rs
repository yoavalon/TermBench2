fn track_sequence() {
    let mut frame = 0;
    loop {
        frame += 1;
        if frame % 100 == 0 {
            println!("{}", frame);
        }
    }
}

fn main() {
    track_sequence();
}