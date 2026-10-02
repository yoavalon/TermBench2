fn tokenize_and_parse(text: &str) -> Vec<String> {
    let tokens: Vec<&str> = text.split_whitespace().collect();
    let parsed: Vec<String> = tokens.into_iter()
        .map(|token| {
            if token.chars().all(char::is_digit) {
                token.to_string()
            } else {
                token.to_string()
            }
        })
        .collect();
    parsed
}

fn main() {
    let text = "The sequence starts with 1, 2, 3 and continues with 4, 5.";
    let result = tokenize_and_parse(text);
    println!("{:?}", result);
}