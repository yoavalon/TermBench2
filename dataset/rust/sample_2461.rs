fn analyze_sequences() -> Vec<usize> {
    let mut state = 0;
    let transitions = [1, 2, 0];
    let mut sequence = vec![state];
    for _ in 0..10 {
        state = transitions[state];
        sequence.push(state);
    }
    sequence
}

fn main() {
    let result = analyze_sequences();
    println!("{:?}", result);
}