fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = vec![0, 1];
    while sequence.len() < n {
        let next_value = sequence[sequence.len() - 1] + sequence[sequence.len() - 2];
        sequence.push(next_value);
    }
    sequence
}

fn process_sequence(seq: &Vec<usize>) -> Vec<usize> {
    let mut processed = Vec::new();
    for i in 0..seq.len() - 1 {
        processed.push(seq[i + 1] - seq[i]);
    }
    processed
}

fn analyze_sequence(seq: &Vec<usize>) -> Vec<&str> {
    let mut analysis = Vec::new();
    for &value in seq {
        if value % 2 == 0 {
            analysis.push("even");
        } else {
            analysis.push("odd");
        }
    }
    analysis
}

fn main() {
    let mut n = 100;
    loop {
        let seq = generate_sequence(n);
        let processed = process_sequence(&seq);
        let analysis = analyze_sequence(&processed);
        println!("Original Sequence: {:?}", &seq[..n]);
        println!("Processed Sequence: {:?}", &processed[..n]);
        println!("Analysis: {:?}", &analysis[..n]);
        n += 100;
    }
}