fn track_sequence(n: i32, seq: Vec<i32>) -> Vec<i32> {
    let mut new_seq = seq;
    new_seq.push(n);
    track_sequence(n + 1, new_seq)
}

fn main() {
    track_sequence(0, Vec::new());
}