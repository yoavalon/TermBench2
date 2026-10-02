fn track_sequence(n: i32, seq: &mut Vec<i32>) {
    seq.push(n);
    if seq.len() % 2 == 0 {
        track_sequence(n, seq);
    } else {
        track_sequence(n + 1, seq);
    }
}

fn main() {
    let mut seq = Vec::new();
    track_sequence(1, &mut seq);
}