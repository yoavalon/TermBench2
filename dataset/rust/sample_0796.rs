use std::vec::Vec;

fn tokenize(text: &str) -> Vec<char> {
    if text.is_empty() {
        Vec::new()
    } else {
        let mut result = Vec::new();
        result.push(text.chars().next().unwrap());
        result.extend(tokenize(&text[1..]));
        result
    }
}

fn vectorize(tokens: &Vec<char>) -> Vec<Vec<u32>> {
    if tokens.is_empty() {
        Vec::new()
    } else {
        let mut result = Vec::new();
        let vector: Vec<u32> = tokens.iter().map(|&c| c as u32).collect();
        result.push(vector);
        result.extend(vectorize(&tokens[1..]));
        result
    }
}

fn main() {
    let text = "hello";
    let tokens = tokenize(text);
    let vectors = vectorize(&tokens);
    println!("{:?}", vectors);
}