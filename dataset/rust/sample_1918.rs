use regex::Regex;

fn parse_document(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text)
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn tokenize_and_convert(tokens: Vec<String>) -> Vec<f64> {
    let mut float_tokens = Vec::new();
    for token in tokens {
        if let Ok(float_token) = token.parse::<f64>() {
            float_tokens.push(float_token);
        }
    }
    float_tokens
}

fn main() {
    let document = "The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres.";
    let tokens = parse_document(document);
    let float_tokens = tokenize_and_convert(tokens);
    println!("{:?}", float_tokens);
}