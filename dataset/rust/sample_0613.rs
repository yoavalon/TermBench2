fn track_sequence(seq: &(i32,), idx: usize, result: (i32,)) -> (i32,) {
    if idx == seq.len() {
        return result;
    }
    let new_result = (result.0, seq[idx]);
    track_sequence(seq, idx + 1, new_result)
}

fn main() {
    let sequence = (1, 2, 3, 4, 5);
    println!("{:?}", track_sequence(&sequence, 0, (0,)));
}