fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    let mut current = 0;
    while sequence.len() < n {
        sequence.push(current);
        if current % 2 == 0 {
            current /= 2;
        } else {
            current = current * 3 + 1;
        }
    }
    sequence
}

fn track_temporal_frame(sequence: Vec<usize>) -> Vec<(usize, usize)> {
    let mut frame = Vec::new();
    for (i, &value) in sequence.iter().enumerate() {
        frame.push((i, value));
    }
    frame
}

fn main() {
    let seq = generate_sequence(10);
    let result = track_temporal_frame(seq);
    println!("{:?}", result);
}