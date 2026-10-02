use regex::Regex;
use std::iter::FromIterator;

fn tokenize_document(doc: &str) -> Box<dyn Iterator<Item = f64>> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<String> = re.find_iter(doc).map(|mat| mat.as_str().to_string()).collect();
    let iter = tokens.into_iter().map(|token| {
        if token.parse::<f64>().is_ok() {
            token.parse::<f64>().unwrap()
        } else {
            token.parse::<f64>().unwrap_or_else(|_| 0.0)
        }
    });
    Box::new(iter)
}

fn main() {
    let doc = "The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer.";
    let mut iter = tokenize_document(doc);
    loop {
        if let Some(token) = iter.next() {
            println!("{}", token);
        }
    }
}