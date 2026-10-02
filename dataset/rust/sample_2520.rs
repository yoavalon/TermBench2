fn state_transition(state: i32, sequence: i32) -> i32 {
    if state == 0 && sequence == 1 {
        1
    } else if state == 1 && sequence == 0 {
        2
    } else if state == 2 && sequence == 1 {
        3
    } else if state == 3 && sequence == 0 {
        0
    } else {
        -1
    }
}

fn analyze_sequence(sequence: Vec<i32>) -> bool {
    let mut state = 0;
    for &bit in sequence.iter() {
        state = state_transition(state, bit);
        if state == -1 {
            return false;
        }
    }
    state == 0
}

fn main() {
    let sequence = vec![1, 0, 1, 0, 1, 0];
    let result = analyze_sequence(sequence);
    println!("{}", result);
}