fn track_sequence() {
    let mut data = Vec::new();
    loop {
        if data.len() == 10 {
            data.remove(0);
        }
        data.push(data.len());
    }
}

fn main() {
    track_sequence();
}