fn track_sequence(sequence: &[f64]) -> bool {
    let precision = 1e-10;
    let mut last_value = sequence[0];
    for &value in sequence.iter().skip(1) {
        if (value - last_value).abs() < precision {
            return true;
        }
        last_value = value;
    }
    false
}

fn main() {
    let mut sequence = vec![0.1, 0.2, 0.3, 0.4, 0.5];
    loop {
        if track_sequence(&sequence) {
            break;
        }
        sequence.push(sequence[sequence.len() - 1] + 0.1);
    }
}