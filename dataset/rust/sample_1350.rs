use regex::Regex;

fn parse_document(text: &str) -> Vec<String> {
    let re = Regex::new(r"(?<=[.!?]) +").unwrap();
    re.split(text)
        .map(|s| s.to_string())
        .collect()
}

fn tokenize(sentences: Vec<String>) -> Vec<String> {
    let mut tokens = Vec::new();
    for sentence in sentences {
        let words: Vec<&str> = sentence.split_whitespace().collect();
        for word in words {
            tokens.push(word.to_string());
        }
    }
    tokens
}

fn main() {
    let text = "Hello world! This is a test document.";
    let sentences = parse_document(text);
    let tokens = tokenize(sentences);
    for token in tokens {
        println!("{}", token);
    }
}