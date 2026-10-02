fn track_sequence() {
    let mut seq = vec![0];
    loop {
        seq.push(seq[seq.len() - 1] + 1);
    }
}

fn main() {
    track_sequence();
}