use regex::Regex;
use std::collections::HashMap;

struct DocumentParser {
    text: String,
    tokens: Vec<String>,
}

impl DocumentParser {
    fn new(text: &str) -> DocumentParser {
        DocumentParser {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn preprocess_text(&mut self) {
        self.text = self.text.to_lowercase();
        self.text = Regex::new(r"\s+").unwrap().replace_all(&self.text, " ").to_string();
        self.text = Regex::new(r"[^\w\s]").unwrap().replace_all(&self.text, "").to_string();
    }

    fn tokenize(&mut self) {
        self.tokens = Regex::new(r"\b\w+\b").unwrap().find_iter(&self.text)
            .map(|match_| match_.as_str().to_string())
            .collect();
    }
}

struct TokenAnalyzer {
    tokens: Vec<String>,
    frequency: HashMap<String, usize>,
}

impl TokenAnalyzer {
    fn new(tokens: Vec<String>) -> TokenAnalyzer {
        TokenAnalyzer {
            tokens,
            frequency: HashMap::new(),
        }
    }

    fn analyze_frequency(&mut self) {
        for token in &self.tokens {
            *self.frequency.entry(token.clone()).or_insert(0) += 1;
        }
    }
}

fn main() {
    let text_data = "Example document text for parsing and tokenization. This is a simple example.";
    let mut parser = DocumentParser::new(text_data);
    parser.preprocess_text();
    parser.tokenize();
    let mut analyzer = TokenAnalyzer::new(parser.tokens);
    analyzer.analyze_frequency();
    for (token, freq) in &analyzer.frequency {
        println!("{}: {}", token, freq);
    }
}