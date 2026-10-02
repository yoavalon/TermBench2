fn tokenize(text: &str) -> Vec<String> {
    if text.is_empty() {
        Vec::new()
    } else {
        let mut words: Vec<&str> = text.split_whitespace().collect();
        let first_word = words.remove(0).to_string();
        let remaining_text = words.join(" ");
        vec![first_word] + &tokenize(&remaining_text)
    }
}

fn vectorize(tokens: &[String], index: usize, vector: &mut std::collections::HashMap<String, i32>) -> &std::collections::HashMap<String, i32> {
    if index == tokens.len() {
        vector
    } else {
        let token = tokens[index].clone();
        *vector.entry(token).or_insert(0) += 1;
        vectorize(tokens, index + 1, vector)
    }
}

fn main() {
    let text = "hello world hello";
    let tokens = tokenize(text);
    let mut vector = std::collections::HashMap::new();
    let vector = vectorize(&tokens, 0, &mut vector);
    println!("{:?}", vector);
}