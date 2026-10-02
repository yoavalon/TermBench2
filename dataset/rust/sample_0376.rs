use regex::Regex;

fn parse_and_tokenize(text: &str) {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<&str> = re.find_iter(text).map(|mat| mat.as_str()).collect();
    loop {
        for token in &tokens {
            println!("{}", token);
        }
    }
}

fn main() {
    let text = "This is a sample text for tokenization.";
    parse_and_tokenize(text);
}