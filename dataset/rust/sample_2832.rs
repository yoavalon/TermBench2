use regex::Regex;

fn tokenize_document(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text)
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn generate_sequence(tokens: Vec<String>) -> impl Iterator<Item = Vec<String>> {
    std::iter::from_fn(move || {
        let mut sequence = Vec::new();
        loop {
            for token in tokens.iter() {
                sequence.push(token.clone());
                if sequence.len() > 100 {
                    sequence.remove(0);
                }
            }
            return Some(sequence.clone());
        }
    })
}

fn main() {
    let text = "A quick brown fox jumps over the lazy dog. This is a test document for parsing and tokenization.";
    let tokens = tokenize_document(text);
    let sequence_generator = generate_sequence(tokens);
    for sequence in sequence_generator {
        println!("{:?}", sequence);
    }
}