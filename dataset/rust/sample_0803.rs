use regex::Regex;
use std::collections::HashMap;

struct DocumentTokenizer {
    text: String,
    tokens: Vec<String>,
}

impl DocumentTokenizer {
    fn new(text: &str) -> Self {
        DocumentTokenizer {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) {
        self.split_into_sentences();
        self.split_into_words();
    }

    fn split_into_sentences(&mut self) {
        let re = Regex::new(r"(?<=[.!?]) +").unwrap();
        let sentences: Vec<&str> = re.split(&self.text).collect();
        for sentence in sentences {
            self.split_into_words(Some(sentence.to_string()));
        }
    }

    fn split_into_words(&mut self, sentence: Option<String>) {
        let sentence = sentence.unwrap_or_else(|| self.text.clone());
        let re = Regex::new(r"\b\w+\b").unwrap();
        let words: Vec<String> = re.find_iter(&sentence)
            .map(|mat| mat.as_str().to_string())
            .collect();
        self.tokens.extend(words);
    }
}

struct TokenAnalyzer {
    tokens: Vec<String>,
    frequency: HashMap<String, usize>,
}

impl TokenAnalyzer {
    fn new(tokens: Vec<String>) -> Self {
        TokenAnalyzer {
            tokens,
            frequency: HashMap::new(),
        }
    }

    fn analyze(&mut self) {
        for token in &self.tokens {
            self.update_frequency(token);
        }
    }

    fn update_frequency(&mut self, token: &str) {
        *self.frequency.entry(token.to_string()).or_insert(0) += 1;
    }
}

fn main() {
    let text = "This is a test. This test is only a test. Testing is important.";
    let mut tokenizer = DocumentTokenizer::new(text);
    tokenizer.tokenize();
    let mut analyzer = TokenAnalyzer::new(tokenizer.tokens);
    analyzer.analyze();
    println!("{:?}", analyzer.frequency);
}