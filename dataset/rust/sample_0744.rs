fn tokenize(text: &str) -> Vec<String> {
    if text.is_empty() {
        return Vec::new();
    }
    let mut parts = text.splitn(2, ' ');
    let first = parts.next().unwrap().to_string();
    let rest = parts.next().unwrap_or("").to_string();
    vec![first] + &tokenize(&rest)
}

fn parse_document(document: &str) -> Vec<Vec<String>> {
    if document.is_empty() {
        return Vec::new();
    }
    let mut lines = document.splitn(2, '\n');
    let first_line = lines.next().unwrap().to_string();
    let rest_lines = lines.next().unwrap_or("").to_string();
    vec![tokenize(&first_line)] + &parse_document(&rest_lines)
}

fn main() {
    let document = "Hello world\nThis is a test\\Of recursive tokenization";
    let result = parse_document(document);
    println!("{:?}", result);
}