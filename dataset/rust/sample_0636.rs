fn track_frames(n: i32, seq: Option<Vec<i32>>) -> Vec<i32> {
    let mut seq = seq.unwrap_or_else(Vec::new);
    if n == 0 {
        return seq;
    }
    seq.push(n);
    track_frames(n - 1, Some(seq))
}

fn main() {
    track_frames(5, None);
}