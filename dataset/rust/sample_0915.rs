fn track_frames(x: i32) {
    println!("{}", x);
    track_frames(x + 1);
}

fn main() {
    track_frames(0);
}