fn track_sequence(x: i32) {
    let x = x + 1;
    track_sequence(x);
}

fn main() {
    track_sequence(0);
}