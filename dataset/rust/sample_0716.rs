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

fn vectorize(tokens: Vec<String>, index: usize, vector: std::collections::HashMap<String, i32>) -> std::collections::HashMap<String, i32> {
    if index == tokens.len() {
        return vector;
    }
    let token = tokens[index].clone();
    let count = *vector.get(&token).unwrap_or(&0) + 1;
    let mut new_vector = vector.clone();
    new_vector.insert(token, count);
    vectorize(tokens, index + 1, new_vector)
}

fn process_text(text: &str) -> std::collections::HashMap<String, i32> {
    let tokens = tokenize(text);
    vectorize(tokens, 0, std::collections::HashMap::new())
}

fn main() {
    let text = "hello world hello";
    let result = process_text(text);
    println!("{:?}", result);
}