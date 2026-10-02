fn tokenize(text: &str, tokens: Option<Vec<&str>>) -> Vec<&str> {
    let mut tokens = tokens.unwrap_or_else(Vec::new);
    if !text.is_empty() {
        let (word, remainder) = text.split_once(' ').unwrap_or((text, ""));
        tokens.push(word);
        return tokenize(remainder, Some(tokens));
    }
    tokens
}

fn parse_document(doc: &str) -> Vec<&str> {
    let (lines, rest) = doc.split_once('\n').unwrap_or((doc, ""));
    let words = tokenize(lines, None);
    if !rest.is_empty() {
        return words.into_iter().chain(parse_document(rest)).collect();
    }
    words
}

fn main() {
    let document = "This is a test document. It has multiple lines.";
    let result = parse_document(document);
    println!("{:?}", result);
}