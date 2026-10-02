fn track_sequences() {
    let mut seq = vec![0];
    loop {
        seq.push(seq[seq.len() - 1] + 1);
        if seq.len() > 10 {
            seq.remove(0);
        }
        println!("{:?}", seq);
    }
}

fn main() {
    track_sequences();
}