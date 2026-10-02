fn process_sequence(sequence: Vec<u32>) -> u32 {
    let mut state = 0;
    let transitions = [
        [1, 2],
        [3, 0],
        [0, 3],
        [2, 1]
    ];
    for &bit in &sequence {
        state = transitions[state as usize][bit as usize];
    }
    state
}

fn main() {
    let sequence = vec![0, 1, 0, 1, 1, 0, 0];
    let result = process_sequence(sequence);
    println!("{}", result);
}