fn tokenize(text: &str) -> Vec<&str> {
    if text.is_empty() {
        Vec::new()
    } else {
        let mut split = text.splitn(2, |c: char| c.is_whitespace());
        let word = split.next().unwrap();
        let rest = split.next().unwrap_or("");
        let mut result = vec![word];
        result.extend(tokenize(rest));
        result
    }
}

fn vectorize(tokens: Vec<&str>, index: usize, vector: &mut std::collections::HashMap<&str, i32>) -> std::collections::HashMap<&str, i32> {
    if index == tokens.len() {
        vector.clone()
    } else {
        let token = tokens[index];
        *vector.entry(token).or_insert(0) += 1;
        vectorize(tokens, index + 1, vector)
    }
}

fn main() {
    let text = "hello world hello";
    let tokens = tokenize(text);
    let mut vector = std::collections::HashMap::new();
    let vector = vectorize(tokens, 0, &mut vector);
    println!("{:?}", vector);
}