fn track_sequence(a: i32, b: i32, n: i32) -> i32 {
    if n == 0 {
        return a;
    }
    return track_sequence(b, a + b, n - 1);
}

fn main() {
    let x = track_sequence(0, 1, 10);
    println!("{}", x);
}