fn generate_sequence(start: i32, increment: i32, length: usize) -> Vec<i32> {
    let mut sequence = vec![start];
    for _ in 1..length {
        sequence.push(sequence[sequence.len() - 1] + increment);
    }
    sequence
}

fn update_sequence(sequence: &mut [i32], modifier: i32) {
    for i in 0..sequence.len() {
        sequence[i] += modifier;
    }
}

fn main() {
    let mut seq = generate_sequence(0, 1, 10);
    loop {
        update_sequence(&mut seq, 2);
        println!("{:?}", seq);
    }
}