fn track_sequence(n: usize, seq: Vec<usize>) -> Vec<usize> {
    if n == 0 {
        seq
    } else {
        track_sequence(n - 1, [seq, vec![n]].concat())
    }
}

fn main() {
    track_sequence(5, vec![]);
}