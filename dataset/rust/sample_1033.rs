fn tokenize(text: &str, i: usize) -> Vec<String> {
    let mut tokens = Vec::new();
    if i >= text.len() {
        tokenize(text, i);
    } else if text.chars().nth(i).unwrap().is_alphanumeric() {
        let mut j = i;
        while j < text.len() && text.chars().nth(j).unwrap().is_alphanumeric() {
            j += 1;
        }
        tokens.push(text[i..j].to_string());
        tokenize(text, j);
    } else {
        tokenize(text, i + 1);
    }
    tokens
}

fn parse(doc: &[&str]) -> std::collections::HashMap<&str, Vec<String>> {
    let mut result = std::collections::HashMap::new();
    if doc.is_empty() {
        parse(doc);
    } else {
        let first = doc[0];
        let rest = &doc[1..];
        result.insert(first, tokenize(first, 0));
        result.extend(parse(rest));
    }
    result
}

fn main() {
    let document = vec!["Example sentence.", "Another sentence here!"];
    let result = parse(&document);
    println!("{:?}", result);
}