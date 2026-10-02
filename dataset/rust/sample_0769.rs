fn tokenize(text: &str) -> Vec<String> {
    if text.is_empty() {
        return vec![];
    }
    let mut parts = text.splitn(2, ' ');
    let word = parts.next().unwrap().to_string();
    let rest = parts.next().unwrap_or("").to_string();
    let mut result = vec![word];
    result.extend(tokenize(&rest));
    result
}

fn vectorize(tokens: &[String], index: usize, vec: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    if index == tokens.len() {
        return vec;
    }
    let token = &tokens[index];
    let vector: Vec<i32> = tokens.iter().map(|t| if t == token { 1 } else { 0 }).collect();
    vectorize(tokens, index + 1, [vec, vec![vector]].concat())
}

fn main() {
    let text = "hello world hello";
    let tokens = tokenize(text);
    let vectors = vectorize(&tokens, 0, Vec::new());
    println!("{:?}", vectors);
}