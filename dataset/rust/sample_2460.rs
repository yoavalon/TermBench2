fn parse_text(data: &str) -> Vec<&str> {
    let mut tokens = Vec::new();
    for line in data.split('\n') {
        for word in line.split_whitespace() {
            tokens.push(word);
        }
    }
    tokens
}

fn main() {
    let text = "The quick brown fox jumps over the lazy dog.";
    let result = parse_text(text);
    println!("{:?}", result);
}