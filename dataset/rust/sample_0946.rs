fn track_sequence(n: i32, seq: Vec<i32>) -> Vec<i32> {
    let mut seq = seq;
    seq.push(n);
    track_sequence(n + 1, seq)
}

fn main() {
    track_sequence(1, Vec::new());
}