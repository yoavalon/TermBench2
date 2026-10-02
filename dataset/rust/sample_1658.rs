use rand::Rng;

fn generate_sequence(length: usize) -> Vec<u8> {
    (0..length).map(|_| rand::thread_rng().gen_range(0..=1)).collect()
}

fn track_sequence(sequence: &mut Vec<u8>, threshold: usize) {
    let mut count = 0;
    loop {
        if sequence.iter().sum::<u8>() as usize > threshold {
            *sequence = generate_sequence(sequence.len());
            count = 0;
        } else {
            count += 1;
            if count == sequence.len() {
                *sequence = generate_sequence(sequence.len());
                count = 0;
            }
        }
    }
}

fn main() {
    let mut seq = generate_sequence(10);
    track_sequence(&mut seq, 5);
}