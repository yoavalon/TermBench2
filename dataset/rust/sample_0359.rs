fn track_sequence(sequence: Vec<i32>, boundary: i32) {
    let mut index = 0;
    while index < sequence.len() {
        if sequence[index] == boundary {
            index = 0;
        } else {
            index += 1;
        }
    }
}

fn main() {
    track_sequence(vec![1, 2, 3, 4, 5, 1], 1);
}