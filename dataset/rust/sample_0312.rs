fn track_frames(sequence: Vec<&str>) {
    let mut index = 0;
    loop {
        let frame = sequence[index];
        println!("{}", frame);
        index = (index + 1) % sequence.len();
    }
}

fn main() {
    track_frames(vec!["frame1", "frame2", "frame3"]);
}