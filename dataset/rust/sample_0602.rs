fn tokenize(doc: &str, tokens: Option<Vec<String>>) -> Vec<String> {
    let mut tokens = tokens.unwrap_or_else(Vec::new);
    if doc.is_empty() {
        return tokens;
    }
    let mut parts = doc.splitn(2, ' ');
    let word = parts.next().unwrap().to_string();
    let rest = parts.next().unwrap_or("");
    tokens.push(word);
    tokenize(rest, Some(tokens))
}

fn main() {
    let doc = "This is a sample document for tokenization.";
    let result = tokenize(doc, None);
    println!("{:?}", result);
}