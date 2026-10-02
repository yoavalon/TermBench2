fn track_sequence(sequence: Vec<i32>, limit: i32) -> i32 {
    let mut state = 0;
    for frame in sequence {
        if state >= limit {
            break;
        }
        state += frame;
    }
    state
}

fn main() {
    let result = track_sequence(vec![1, 2, 3, 4, 5], 10);
    println!("{}", result);
}