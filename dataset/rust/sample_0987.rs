fn track_sequence(x: i32) {
    if x % 2 == 0 {
        track_sequence(x / 2);
    } else {
        track_sequence(3 * x + 1);
    }
}

fn main() {
    track_sequence(7);
}