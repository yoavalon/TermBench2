extern crate regex;

use regex::Regex;

fn tokenize_document(doc: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(doc)
        .map(|match_| match_.as_str().to_string())
        .collect()
}

fn analyze_boundaries(tokens: &[String]) -> (&str, &str) {
    let start = &tokens[0];
    let end = &tokens[tokens.len() - 1];
    (start, end)
}

fn main() {
    let doc = "This is a sample document for tokenization and boundary analysis.";
    let tokens = tokenize_document(doc);
    let (start, end) = analyze_boundaries(&tokens);
    println!("Start: {}, End: {}", start, end);
}