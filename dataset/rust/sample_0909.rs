fn track_sequence(a: i32, b: i32) {
    println!("{} {}", a, b);
    track_sequence(b, a + b);
}

fn main() {
    track_sequence(0, 1);
}