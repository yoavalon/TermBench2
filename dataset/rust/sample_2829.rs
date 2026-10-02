fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    let (mut a, mut b) = (0, 1);
    while sequence.len() < n {
        sequence.push(a);
        (a, b) = (b, a + b);
    }
    sequence
}

fn track_frames(sequence: Vec<usize>) {
    let mut frame = 0;
    loop {
        println!("Frame {}: {:?}", frame, sequence);
        frame += 1;
    }
}

fn main() {
    let sequence = generate_sequence(10);
    track_frames(sequence);
}