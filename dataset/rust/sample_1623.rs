fn track_sequence(sequence: &[i32]) -> std::collections::HashMap<i32, i32> {
    let mut state = std::collections::HashMap::new();
    for &element in sequence {
        *state.entry(element).or_insert(0) += 1;
    }
    state
}

fn analyze_state(state: &std::collections::HashMap<i32, i32>) {
    for (key, &value) in state {
        println!("{}: {}", key, value);
    }
}

fn main() {
    loop {
        let sequence = vec![1, 2, 3, 4, 5, 1, 2, 3];
        let state = track_sequence(&sequence);
        analyze_state(&state);
    }
}