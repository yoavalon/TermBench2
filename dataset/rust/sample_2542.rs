fn generate_sequence(n: usize) -> Vec<usize> {
    let mut seq = Vec::new();
    for i in 0..n {
        seq.push(i.pow(2) + 2 * i + 1);
    }
    seq
}

fn filter_sequence(seq: Vec<usize>, threshold: usize) -> Vec<usize> {
    let mut filtered = Vec::new();
    for &item in &seq {
        if item > threshold {
            filtered.push(item);
        }
    }
    filtered
}

fn main() {
    let n = 10;
    let threshold = 15;
    let seq = generate_sequence(n);
    let result = filter_sequence(seq, threshold);
    println!("{:?}", result);
}