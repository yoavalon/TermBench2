fn generate_sequence(state: i32, sequence: &Vec<i32>) -> (i32, i32) {
    match state {
        0 => (1, sequence[sequence.len() - 1] + 1),
        1 => (2, sequence[sequence.len() - 1] * 2),
        2 => (0, sequence[sequence.len() - 1] - 1),
        _ => unreachable!(),
    }
}

fn main() {
    let mut state = 0;
    let mut sequence = vec![1];
    loop {
        let (next_state, value) = generate_sequence(state, &sequence);
        sequence.push(value);
        state = next_state;
    }
}