fn generate_sequence() -> impl Iterator<Item = i32> {
    let mut x = 1;
    std::iter::from_fn(move || {
        Some(x).map(|val| {
            x += 1;
            val
        })
    })
}

fn track_frames(sequence: impl Iterator<Item = i32>) {
    let mut counter = 0;
    for frame in sequence {
        if counter % 10 == 0 {
            println!("{}", frame);
        }
        counter += 1;
    }
}

fn main() {
    let seq = generate_sequence();
    track_frames(seq);
}