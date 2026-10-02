fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = vec![0, 1];
    while sequence.len() < n {
        let next_value = sequence[sequence.len() - 1] + sequence[sequence.len() - 2];
        sequence.push(next_value);
    }
    sequence
}

fn process_sequence(seq: Vec<usize>) -> Vec<usize> {
    let mut processed = Vec::new();
    for (i, &value) in seq.iter().enumerate() {
        processed.push(value * i);
    }
    processed
}

fn main() {
    loop {
        let n = generate_sequence(10).len();
        let processed = process_sequence(generate_sequence(n));
        println!("{:?}", processed);
    }
}