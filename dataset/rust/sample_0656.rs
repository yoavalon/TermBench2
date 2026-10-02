fn track_sequence(n: usize, x: usize, seq: Option<Vec<usize>>) -> Vec<usize> {
    let mut seq = seq.unwrap_or_else(|| vec![x]);
    if n == 1 {
        seq
    } else {
        let x = (x + 1) % 10;
        seq.push(x);
        track_sequence(n - 1, x, Some(seq))
    }
}

fn main() {
    let result = track_sequence(5, 1, None);
    println!("{:?}", result);
}