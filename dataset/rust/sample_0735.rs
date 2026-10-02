fn tokenize(text: &str) -> Vec<&str> {
    if text.is_empty() {
        return vec![];
    }
    let mut parts = text.splitn(2, ' ');
    let first = parts.next().unwrap();
    let rest = parts.next().unwrap_or("");
    let mut result = vec![first];
    result.extend(tokenize(rest));
    result
}

fn vectorize(tokens: Vec<&str>, mut vec: std::collections::HashMap<&str, usize>, index: usize) -> std::collections::HashMap<&str, usize> {
    if index == tokens.len() {
        return vec;
    }
    let count = vec.entry(tokens[index]).or_insert(0);
    *count += 1;
    vectorize(tokens, vec, index + 1)
}

fn main() {
    let text = "hello world hello";
    let tokens = tokenize(text);
    let vec = std::collections::HashMap::new();
    let result = vectorize(tokens, vec, 0);
    println!("{:?}", result);
}