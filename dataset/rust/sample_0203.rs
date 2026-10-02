use regex::Regex;
use std::collections::HashMap;

struct DocumentParser {
    text: String,
    tokens: Vec<String>,
}

impl DocumentParser {
    fn new(text: &str) -> Self {
        DocumentParser {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text.to_lowercase())
            .map(|match_| match_.as_str().to_string())
            .collect();
    }

    fn filter_tokens(&mut self, min_length: usize) {
        self.tokens = self.tokens
            .into_iter()
            .filter(|token| token.len() > min_length)
            .collect();
    }
}

struct TokenAnalyzer {
    tokens: Vec<String>,
    freq_dict: HashMap<String, usize>,
}

impl TokenAnalyzer {
    fn new(tokens: Vec<String>) -> Self {
        TokenAnalyzer {
            tokens,
            freq_dict: HashMap::new(),
        }
    }

    fn calculate_frequencies(&mut self) {
        for token in &self.tokens {
            *self.freq_dict.entry(token.clone()).or_insert(0) += 1;
        }
    }

    fn get_top_frequencies(&self, n: usize) -> HashMap<String, usize> {
        let mut sorted: Vec<_> = self.freq_dict.iter().collect();
        sorted.sort_by(|a, b| b.1.cmp(a.1));
        sorted.into_iter().take(n).map(|(&k, &v)| (k.to_string(), v)).collect()
    }
}

fn main() {
    let sample_text = "This is a sample text for parsing and tokenization. Let's see how it works.";
    let mut parser = DocumentParser::new(sample_text);
    parser.tokenize();
    parser.filter_tokens(3);
    let analyzer = TokenAnalyzer::new(parser.tokens);
    analyzer.calculate_frequencies();
    let top_frequencies = analyzer.get_top_frequencies(5);
    println!("{:?}", top_frequencies);
}