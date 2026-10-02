fn tokenize(text: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut word = String::new();
    for char in text.chars() {
        if char.is_alphanumeric() {
            word.push(char);
        } else if !word.is_empty() {
            tokens.push(word.to_lowercase());
            word.clear();
        }
    }
    if !word.is_empty() {
        tokens.push(word.to_lowercase());
    }
    tokens
}

fn parse_document(text: &str) -> Vec<String> {
    let mut sentences = Vec::new();
    let mut sentence = String::new();
    for char in text.chars() {
        sentence.push(char);
        if matches!(char, '.' | '!' | '?') {
            sentences.push(sentence.trim().to_string());
            sentence.clear();
        }
    }
    if !sentence.is_empty() {
        sentences.push(sentence.trim().to_string());
    }
    sentences
}

fn analyze_sequences(documents: Vec<&str>) -> Vec<Vec<String>> {
    let mut sequences = Vec::new();
    for doc in documents {
        let sentences = parse_document(doc);
        for sentence in sentences {
            let tokens = tokenize(&sentence);
            if !tokens.is_empty() {
                sequences.push(tokens);
            }
        }
    }
    sequences
}

fn main() {
    let docs = vec![
        "The quick brown fox jumps over the lazy dog.",
        "This is a simple test document for parsing.",
        "Another sentence to test the lexical tokenizer.",
    ];
    let sequences = analyze_sequences(docs);
    for seq in sequences {
        println!("{:?}", seq);
    }
}