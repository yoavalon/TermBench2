fn tokenize(text: &str, tokens: Vec<char>) -> Vec<char> {
    if text.is_empty() {
        tokens
    } else {
        let mut new_tokens = tokens;
        new_tokens.push(text.chars().next().unwrap());
        tokenize(&text[1..], new_tokens)
    }
}

fn main() {
    let result = tokenize("hello world", Vec::new());
    println!("{:?}", result);
}