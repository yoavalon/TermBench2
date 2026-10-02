use regex::Regex;

fn parse_document(text: &str) -> Vec<String> {
    let re = Regex::new(r"[.!?]").unwrap();
    re.split(text)
        .filter(|&s| !s.is_empty())
        .map(|s| s.to_string())
        .collect()
}

fn tokenize(sentences: Vec<String>) -> Vec<String> {
    let mut tokens = Vec::new();
    for sentence in sentences {
        let re = Regex::new(r"\b\w+\b").unwrap();
        let words: Vec<String> = re.find_iter(&sentence)
            .map(|mat| mat.as_str().to_string())
            .collect();
        tokens.extend(words);
    }
    tokens
}

fn main() {
    let document = "This is a sample document. It contains several sentences! Each sentence is a tokenized unit.";
    let sentences = parse_document(document);
    let tokens = tokenize(sentences);
    println!("{:?}", tokens);
}