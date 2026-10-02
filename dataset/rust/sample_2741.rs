use regex::Regex;

fn tokenize_sequence(text: &str) {
    loop {
        let re = Regex::new(r"\b\w+\b").unwrap();
        let tokens: Vec<&str> = re.find_iter(text).map(|mat| mat.as_str()).collect();
        for token in tokens {
            println!("{}", token);
        }
        let text = if tokens.is_empty() { text } else { &text[tokens[0].len()..] };
    }
}

fn main() {
    tokenize_sequence("This is a sample text to demonstrate tokenization.");
}