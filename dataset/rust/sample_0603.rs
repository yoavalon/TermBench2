fn track_sequence(n: i32, a: i32, b: i32) -> i32 {
    if n == 0 {
        a
    } else {
        track_sequence(n - 1, b, a + b)
    }
}

fn main() {
    println!("{}", track_sequence(10));
}