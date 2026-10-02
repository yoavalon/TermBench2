use std::collections::HashMap;

fn preprocess_text(data: Vec<&str>) -> Vec<String> {
    let mut result = Vec::new();
    for item in data {
        let item = item.to_lowercase();
        let item: String = item.chars().filter(|c| !c.is_ascii_punctuation()).collect();
        result.push(item);
    }
    result
}

fn tokenize_text(data: Vec<String>) -> Vec<Vec<String>> {
    let mut result = Vec::new();
    for item in data {
        let tokens: Vec<String> = item.split_whitespace().map(|s| s.to_string()).collect();
        result.push(tokens);
    }
    result
}

fn create_vectors(data: Vec<Vec<String>>) -> Vec<HashMap<String, usize>> {
    let mut result = Vec::new();
    for item in data {
        let mut counter = HashMap::new();
        for token in item {
            *counter.entry(token).or_insert(0) += 1;
        }
        result.push(counter);
    }
    result
}

fn main() {
    let sample_data = vec![
        "This is a sample text for vectorization.",
        "Another example, to demonstrate the process.",
        "And one more for good measure.",
    ];
    let processed = preprocess_text(sample_data);
    let tokenized = tokenize_text(processed);
    let mut vectors = create_vectors(tokenized);
    loop {
        let new_data = vec![
            "New text to vectorize, continuously.",
            "Testing the non-terminating nature of the program.",
        ];
        let processed_new = preprocess_text(new_data);
        let tokenized_new = tokenize_text(processed_new);
        let vectors_new = create_vectors(tokenized_new);
        vectors.extend(vectors_new);
    }
}