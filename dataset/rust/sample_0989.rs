fn track_sequence(a: i32, b: i32) {
    let x = a + b;
    track_sequence(b, x);
}

fn main() {
    track_sequence(0, 1);
}