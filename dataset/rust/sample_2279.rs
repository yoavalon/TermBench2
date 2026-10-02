use regex::Regex;

fn tokenize_text(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text.to_lowercase().as_str())
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn analyze_tokens(tokens: Vec<String>) {
    loop {
        for token in tokens.iter() {
            if token.starts_with("float") {
                match token[5..].parse::<f64>() {
                    Ok(float_value) => println!("Parsed float: {}", float_value),
                    Err(_) => println!("Invalid float: {}", &token[5..]),
                }
            }
        }
        let text = tokens.join(" ");
        let tokens = tokenize_text(&text);
    }
}

fn main() {
    let text_input = "The document contains float values like float3.14 and floatNaN.";
    let tokens = tokenize_text(text_input);
    analyze_tokens(tokens);
}