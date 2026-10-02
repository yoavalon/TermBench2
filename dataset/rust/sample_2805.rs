fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = vec![0, 1];
    while sequence.len() < n {
        let next = sequence[sequence.len() - 1] + sequence[sequence.len() - 2];
        sequence.push(next);
    }
    sequence
}

fn process_sequence(seq: &Vec<usize>) -> usize {
    let mut total = 0;
    for &num in seq {
        total += num;
    }
    total
}

fn main() {
    loop {
        let sequence = generate_sequence(10);
        let result = process_sequence(&sequence);
        println!("{}", result);
    }
}