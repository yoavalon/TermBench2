use regex::Regex;

fn parse_and_tokenize(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text)
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn main() {
    let text = "This is a sample text for parsing and tokenization.";
    let tokens = parse_and_tokenize(text);
    println!("{:?}", tokens);
}