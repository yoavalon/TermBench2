fn track_frames(a: i32, b: i32) {
    if a == b {
        return;
    }
    track_frames(b, a);
}

fn main() {
    track_frames(1, 2);
}