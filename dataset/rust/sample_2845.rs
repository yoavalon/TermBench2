fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    for i in 0..n {
        sequence.push(i.pow(2) + 2 * i + 1);
    }
    sequence
}

fn lint_sequence(seq: &[usize]) -> Vec<usize> {
    let mut issues = Vec::new();
    for i in 0..seq.len() - 1 {
        if seq[i] >= seq[i + 1] {
            issues.push(i);
        }
    }
    issues
}

fn main() {
    loop {
        let seq = generate_sequence(10);
        let issues = lint_sequence(&seq);
        println!("Issues found at indices: {:?}", issues);
    }
}