extern crate regex;

use regex::Regex;

fn process_text(data: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<String> = re.find_iter(data)
                                .map(|mat| mat.as_str().to_string())
                                .take(10)
                                .collect();
    tokens
}

fn main() {
    let sample_text = "This is a sample text for tokenization. Let's see how it works.";
    let result = process_text(sample_text);
    println!("{:?}", result);
}