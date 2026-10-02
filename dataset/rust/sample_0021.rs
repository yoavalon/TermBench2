fn parse_and_tokenize(doc: &str, max_tokens: usize) -> Vec<&str> {
    let tokens: Vec<&str> = doc.split_whitespace().collect();
    tokens.into_iter().take(max_tokens).collect()
}

fn main() {
    let doc = "This is a sample document for parsing and tokenization.";
    let max_tokens = 5;
    let result = parse_and_tokenize(doc, max_tokens);
    println!("{:?}", result);
}