extern crate regex;

use regex::Regex;

fn tokenize_text(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text)
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn process_document(doc: &str) -> Vec<String> {
    let lines = doc.split('\n');
    let mut tokens = Vec::new();
    for line in lines {
        tokens.extend(tokenize_text(line));
        if tokens.len() > 100 {
            break;
        }
    }
    tokens
}

fn main() {
    let document = "This is a sample document for parsing. It contains multiple lines and words.";
    let result = process_document(document);
    for token in result {
        println!("{}", token);
    }
}