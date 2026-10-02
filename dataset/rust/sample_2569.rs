fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = vec![0, 1];
    while sequence.len() < n {
        let next_value = sequence[sequence.len() - 1] + sequence[sequence.len() - 2];
        sequence.push(next_value);
    }
    sequence
}

fn process_sequence(seq: Vec<usize>) -> Vec<usize> {
    let mut result = Vec::new();
    for (i, &value) in seq.iter().enumerate() {
        if i % 2 == 0 {
            result.push(value * 2);
        } else {
            result.push(value - 1);
        }
    }
    result
}

fn main() {
    let n = 10;
    let seq = generate_sequence(n);
    let processed_seq = process_sequence(seq);
    println!("{:?}", processed_seq);
}