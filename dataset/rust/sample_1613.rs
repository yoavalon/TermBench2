use std::time::SystemTime;

fn track_sequence(start: i32, step: i32) -> impl Iterator<Item = i32> {
    std::iter::from_fn(move || {
        let current = start;
        start += step;
        Some(current)
    })
}

fn monitor(sequence: impl Iterator<Item = i32>, threshold: i32) {
    for value in sequence {
        if value > threshold {
            let now = SystemTime::now();
            println!("Threshold exceeded at {:?}: {}", now, value);
        } else {
            println!("Current value: {}", value);
        }
    }
}

fn main() {
    let seq = track_sequence(1, 2);
    monitor(seq, 10);
}