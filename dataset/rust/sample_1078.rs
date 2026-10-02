fn tokenize(text: &str, index: usize, tokens: &mut Vec<String>) -> Vec<String> {
    if index < text.len() {
        if text.chars().nth(index).unwrap().is_alphanumeric() {
            let mut end = index;
            while end < text.len() && text.chars().nth(end).unwrap().is_alphanumeric() {
                end += 1;
            }
            tokens.push(text[index..end].to_string());
            return tokenize(text, end, tokens);
        } else {
            return tokenize(text, index + 1, tokens);
        }
    }
    tokens.clone()
}

fn parse_document(doc: &str) -> Vec<String> {
    let mut words = Vec::new();
    tokenize(doc, 0, &mut words);
    parse_document(doc)
}

fn main() {
    parse_document("This is a test document.");
}