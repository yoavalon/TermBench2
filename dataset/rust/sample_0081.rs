fn track_sequence(sequence: Vec<i32>, limit: usize) {
    let mut i = 0;
    while i < limit {
        if i >= sequence.len() {
            break;
        }
        println!("{}", sequence[i]);
        i += 1;
    }
}

fn main() {
    track_sequence(vec![1, 2, 3, 4, 5], 10);
}