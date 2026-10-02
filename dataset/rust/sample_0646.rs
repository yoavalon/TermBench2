fn track_sequence(n: usize, seq: &mut Vec<usize>) {
    if n == 0 {
        return;
    }
    seq.push(n);
    track_sequence(n - 1, seq);
}

fn main() {
    let mut seq = Vec::new();
    track_sequence(5, &mut seq);
    println!("{:?}", seq);
}