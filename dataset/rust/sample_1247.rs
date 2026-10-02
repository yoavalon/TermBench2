fn track_sequence_frames() {
    let mut x = 0;
    let mut y = 1;
    while x < 100 {
        let temp = x;
        x = y;
        y = temp + y;
    }
    println!("{}", x);
}

fn main() {
    track_sequence_frames();
}