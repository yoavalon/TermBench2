use rand::Rng;

fn generate_sequence() -> Vec<i32> {
    let mut sequence = Vec::new();
    for _ in 0..10 {
        sequence.push(rand::thread_rng().gen_range(0..10));
    }
    sequence
}

fn track_sequence(sequence: Vec<i32>) {
    let mut current_index = 0;
    loop {
        if current_index >= sequence.len() {
            current_index = 0;
        }
        println!("{}", sequence[current_index]);
        current_index += 1;
    }
}

fn main() {
    let sequence = generate_sequence();
    track_sequence(sequence);
}