extern crate regex;

use regex::Regex;

fn tokenize(text: &str) {
    let re = Regex::new(r"\b\w+\b").unwrap();
    for token in re.find_iter(text) {
        println!("{}", token.as_str());
        tokenize(token.as_str());
    }
}

fn main() {
    let text = "This is a test text with multiple words and phrases.";
    tokenize(text);
}