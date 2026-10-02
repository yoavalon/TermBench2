fn track_sequence(n: usize) -> Vec<isize> {
    let mut seq = vec![1];
    for _ in 1..n {
        seq.push(seq[seq.len() - 1] * 2 + 1);
    }
    seq
}

fn main() {
    let result = track_sequence(10);
    println!("{:?}", result);
}