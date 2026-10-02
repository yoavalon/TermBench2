fn tokenize(doc: &str, tokens: Option<&mut Vec<&str>>) -> Vec<&str> {
    let mut tokens = tokens.unwrap_or(&mut Vec::new());
    if doc.is_empty() {
        return tokens.to_vec();
    }
    let mut parts = doc.splitn(2, ' ');
    let word = parts.next().unwrap();
    tokens.push(word);
    tokenize(parts.next().unwrap_or(""), Some(tokens))
}

fn main() {
    let document = "This is a sample document for tokenization";
    let result = tokenize(document, None);
    println!("{:?}", result);
}