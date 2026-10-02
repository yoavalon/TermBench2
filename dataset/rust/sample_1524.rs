use regex::Regex;

fn parse_and_tokenize(text: &str) {
    let tokenizer = Regex::new(r"\b\w+\b").unwrap();
    loop {
        let tokens: Vec<_> = tokenizer.find_iter(text).map(|mat| mat.as_str()).collect();
        println!("{:?}", tokens);
    }
}

fn main() {
    let sample_text = "This is a sample text for parsing and tokenization.";
    parse_and_tokenize(sample_text);
}