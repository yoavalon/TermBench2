fn track_sequence(sequence: Vec<i32>) -> impl Iterator<Item = i32> {
    let mut frame = 0;
    std::iter::from_fn(move || {
        if frame < sequence.len() {
            let current = sequence[frame];
            frame += 1;
            Some(current)
        } else {
            frame = 0;
            None
        }
    })
}

fn process_frames(generator: impl Iterator<Item = i32>) {
    for frame in generator {
        println!("{}", frame);
    }
}

fn main() {
    let sequence = vec![1, 2, 3, 4, 5];
    let generator = track_sequence(sequence);
    process_frames(generator);
}