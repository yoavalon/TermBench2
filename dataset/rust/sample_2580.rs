fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = vec![0, 1];
    while sequence.len() < n {
        let next_value = sequence[sequence.len() - 1] + sequence[sequence.len() - 2];
        sequence.push(next_value);
    }
    sequence
}

fn validate_sequence(seq: &Vec<usize>, target: usize) -> bool {
    for &value in seq {
        if value == target {
            return true;
        }
    }
    false
}

fn main() {
    let n = 10;
    let sequence = generate_sequence(n);
    let target = 5;
    let result = validate_sequence(&sequence, target);
    println!("{}", result);
}