fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    for i in 1..=n {
        let term = i * (i + 1) / 2;
        sequence.push(term);
    }
    sequence
}

fn analyze_sequence(seq: &Vec<usize>) -> (usize, usize, f64) {
    let max_term = *seq.iter().max().unwrap();
    let min_term = *seq.iter().min().unwrap();
    let avg_term = seq.iter().sum::<usize>() as f64 / seq.len() as f64;
    (max_term, min_term, avg_term)
}

fn main() {
    let n = 10;
    let seq = generate_sequence(n);
    let (max_t, min_t, avg_t) = analyze_sequence(&seq);
    println!("Max: {}, Min: {}, Avg: {}", max_t, min_t, avg_t);
}