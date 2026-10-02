use regex::Regex;

fn analyze_text(data: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<&str> = re.find_iter(data).map(|mat| mat.as_str()).collect();
    let float_tokens: Vec<String> = tokens
        .into_iter()
        .filter(|token| Regex::new(r"^\d+\.\d+$").unwrap().is_match(token))
        .map(|s| s.to_string())
        .collect();
    float_tokens
}

fn main() {
    let text = "The value of pi is approximately 3.14159. The number e is roughly 2.71828.";
    let result = analyze_text(text);
    println!("{:?}", result);
}