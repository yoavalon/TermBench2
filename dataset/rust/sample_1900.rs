use regex::Regex;

fn parse_text(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<&str> = re.find_iter(text).map(|mat| mat.as_str()).collect();
    let float_tokens: Vec<String> = tokens
        .into_iter()
        .filter(|token| Regex::new(r"^\d+\.\d+$").unwrap().is_match(token))
        .map(String::from)
        .collect();
    float_tokens
}

fn main() {
    let text = "The value of pi is approximately 3.14159. The number 2.71828 is also important.";
    let result = parse_text(text);
    println!("{:?}", result);
}