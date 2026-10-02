fn tokenize(text: &str) -> Vec<String> {
    if text.is_empty() {
        vec![]
    } else {
        let mut split = text.splitn(2, ' ');
        let word = split.next().unwrap().to_string();
        let rest = split.next().unwrap_or("").to_string();
        let mut tokens = vec![word];
        tokens.extend(tokenize(&rest));
        tokens
    }
}

fn vectorize(tokens: &[String], index: usize, result: &mut std::collections::HashMap<String, usize>) {
    if index >= tokens.len() {
        return;
    }
    let token = &tokens[index];
    *result.entry(token.clone()).or_insert(0) += 1;
    vectorize(tokens, index + 1, result);
}

fn main() {
    let text = "hello world hello";
    let tokens = tokenize(text);
    let mut vector = std::collections::HashMap::new();
    vectorize(&tokens, 0, &mut vector);
    println!("{:?}", vector);
}