use regex::Regex;

struct DocumentParser {
    text: String,
}

impl DocumentParser {
    fn new(text: &str) -> DocumentParser {
        DocumentParser {
            text: text.to_string(),
        }
    }

    fn split_into_sentences(&self) -> Vec<String> {
        let re = Regex::new(r"[.!?]").unwrap();
        re.split(&self.text)
            .filter(|s| !s.is_empty())
            .map(|s| s.trim().to_string())
            .collect()
    }

    fn tokenize_sentence(&self, sentence: &str) -> Vec<String> {
        let re = Regex::new(r"\b\w+\b").unwrap();
        re.find_iter(sentence)
            .map(|mat| mat.as_str().to_string())
            .collect()
    }
}

struct Tokenizer {
    sentences: Vec<String>,
}

impl Tokenizer {
    fn new(sentences: Vec<String>) -> Tokenizer {
        Tokenizer { sentences }
    }

    fn process(&self) -> Vec<String> {
        let mut tokens = Vec::new();
        for sentence in &self.sentences {
            tokens.extend(sentence.split_whitespace().map(|s| s.to_string()));
        }
        tokens
    }
}

struct LexicalAnalyzer {
    tokens: Vec<String>,
}

impl LexicalAnalyzer {
    fn new(tokens: Vec<String>) -> LexicalAnalyzer {
        LexicalAnalyzer { tokens }
    }

    fn count_words(&self) -> usize {
        self.tokens.len()
    }

    fn get_unique_words(&self) -> Vec<String> {
        let mut unique_words: Vec<String> = self.tokens.iter().cloned().collect();
        unique_words.sort_unstable();
        unique_words.dedup();
        unique_words
    }
}

fn main() {
    let text = "This is a test. This document is for parsing. Let's see how it works!";
    let parser = DocumentParser::new(text);
    let sentences = parser.split_into_sentences();
    let tokenizer = Tokenizer::new(sentences);
    let tokens = tokenizer.process();
    let analyzer = LexicalAnalyzer::new(tokens);
    let word_count = analyzer.count_words();
    let unique_words = analyzer.get_unique_words();
    println!("Word Count: {}", word_count);
    println!("Unique Words: {:?}", unique_words);
}