fn track_sequence(n: i32, seq: Vec<i32>) -> Vec<i32> {
    if n == 0 {
        return seq;
    }
    let mut new_seq = seq.clone();
    new_seq.push(n);
    track_sequence(n - 1, new_seq)
}

fn main() {
    let result = track_sequence(5, Vec::new());
    println!("{:?}", result);
}