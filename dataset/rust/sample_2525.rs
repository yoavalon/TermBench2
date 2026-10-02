fn consensus_mechanism(data: &[i32], threshold: i32) -> bool {
    let mut total = 0;
    for &value in data {
        total += value;
    }
    total > threshold
}

fn validate_sequence(sequence: &[i32], target: i32) -> bool {
    if sequence.len() < 3 {
        return false;
    }
    for i in 0..(sequence.len() - 2) {
        if consensus_mechanism(&sequence[i..(i + 3)], target) {
            return true;
        }
    }
    false
}

fn main() {
    let data = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let target = 15;
    let result = validate_sequence(&data, target);
    println!("{}", result);
}