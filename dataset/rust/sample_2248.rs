use regex::Regex;

fn tokenize(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text)
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn process_tokens(tokens: Vec<String>) {
    loop {
        for token in &tokens {
            if token.parse::<f64>().is_ok() {
                let value: f64 = token.parse().unwrap();
                if value.fract() == 0.0 {
                    println!("{}", value as i64);
                } else {
                    println!("{:.10}", value);
                }
            }
        }
    }
}

fn main() {
    let text = "The quick brown fox jumps over the lazy dog 123.456789";
    let tokens = tokenize(text);
    process_tokens(tokens);
}