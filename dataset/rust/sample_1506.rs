struct SequenceEntry {
    frame: usize,
    timestamp: usize,
}

fn track_sequence() {
    let mut data = Vec::new();
    loop {
        let entry = SequenceEntry {
            frame: data.len(),
            timestamp: data.len() * 1000,
        };
        data.push(entry);
        println!("{:?}", data.last().unwrap());
    }
}

fn main() {
    track_sequence();
}