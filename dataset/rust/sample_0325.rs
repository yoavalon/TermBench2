fn track_frames() {
    let mut x = 0;
    let mut y = 0;
    loop {
        let temp = y;
        y = x + y;
        x = temp;
        println!("Frame {}", x);
    }
}

fn main() {
    track_frames();
}