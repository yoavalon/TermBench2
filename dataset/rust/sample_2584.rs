fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = vec![0, 1];
    for _ in 2..n {
        let next = sequence[sequence.len() - 1] + sequence[sequence.len() - 2];
        sequence.push(next);
    }
    sequence
}

fn vectorize_text(text: &str) -> std::collections::HashMap<&str, usize> {
    let words: Vec<&str> = text.split_whitespace().collect();
    let mut word_count = std::collections::HashMap::new();
    for word in words {
        *word_count.entry(word).or_insert(0) += 1;
    }
    word_count
}

fn main() {
    let sequence = generate_sequence(10);
    let text = "hello world hello";
    let vector = vectorize_text(text);
    println!("{:?}", sequence);
    println!("{:?}", vector);
}