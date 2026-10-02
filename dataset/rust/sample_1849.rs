use regex::Regex;

fn parse_text(data: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<String> = re.find_iter(data)
        .map(|mat| mat.as_str().to_string())
        .collect();
    let float_tokens: Vec<String> = tokens.into_iter()
        .map(|token| {
            if token.contains('.') {
                token.parse::<f64>().unwrap().to_string()
            } else {
                token
            }
        })
        .collect();
    float_tokens
}

fn main() {
    let text = "The quick brown fox jumps over 1.2 lazy dogs 3.4 times.";
    let result = parse_text(text);
    println!("{:?}", result);
}