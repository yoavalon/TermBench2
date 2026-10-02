fn track_sequences() {
    let mut seq = Vec::new();
    loop {
        seq.push(seq.len());
        println!("{:?}", seq);
    }
}

fn main() {
    track_sequences();
}