use std::collections::HashMap;

fn tokenize_text(text: &str) -> Vec<String> {
    text.to_lowercase()
        .split_whitespace()
        .filter_map(|word| {
            let re = regex::Regex::new(r"\b\w+\b").unwrap();
            if re.is_match(word) {
                Some(word.to_string())
            } else {
                None
            }
        })
        .collect()
}

fn count_frequent_tokens(tokens: Vec<String>, n: usize) -> Vec<(String, usize)> {
    let mut frequency = HashMap::new();
    for token in tokens {
        *frequency.entry(token).or_insert(0) += 1;
    }
    let mut sorted_frequency: Vec<(String, usize)> = frequency.into_iter().collect();
    sorted_frequency.sort_by(|a, b| b.1.cmp(&a.1));
    sorted_frequency.into_iter().take(n).collect()
}

fn main() {
    let text = "This is a test text. This text will be tokenized and analyzed for frequent tokens.";
    let tokens = tokenize_text(text);
    let frequent_tokens = count_frequent_tokens(tokens, 5);
    println!("{:?}", frequent_tokens);
}