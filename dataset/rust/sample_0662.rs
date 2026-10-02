fn track_sequence(x: i32, n: i32, a: Vec<i32>) -> Vec<i32> {
    if n == 0 {
        a
    } else {
        track_sequence(x + 1, n - 1, [a, vec![x]].concat())
    }
}

fn main() {
    let result = track_sequence(0, 5, Vec::new());
    println!("{:?}", result);
}