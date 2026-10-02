fn tokenize(text: &str, tokens: Option<Vec<&str>>) -> Vec<&str> {
    let mut tokens = tokens.unwrap_or_else(Vec::new);
    let mut start = 0;
    for (i, char) in text.char_indices() {
        if char.is_whitespace() {
            if i > start {
                tokens.push(&text[start..i]);
            }
            start = i + char.len_utf8();
        }
    }
    if start < text.len() {
        tokens.push(&text[start..]);
    }
    tokens
}

fn parse_document(doc: &str) -> Vec<&str> {
    if doc.is_empty() {
        return Vec::new();
    }
    let (first_line, rest) = doc.split_once('\n').unwrap_or((doc, ""));
    let mut result = tokenize(first_line, None);
    result.extend(parse_document(rest));
    result
}

fn main() {
    let document = "Hello world\nThis is a test document\nWith multiple lines";
    let result = parse_document(document);
    println!("{:?}", result);
}