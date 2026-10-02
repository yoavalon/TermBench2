use regex::Regex;
use std::collections::HashMap;

struct TextProcessor {
    text: String,
    tokens: Vec<String>,
}

impl TextProcessor {
    fn new(text: &str) -> Self {
        TextProcessor {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) -> Vec<String> {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text)
                           .map(|mat| mat.as_str().to_string())
                           .collect();
        self.tokens.clone()
    }

    fn filter_tokens(&self) -> Vec<String> {
        self.tokens.iter()
                  .filter(|&&token| token.len() > 3)
                  .cloned()
                  .collect()
    }
}

struct NumericParser {
    tokens: Vec<String>,
    numeric_tokens: Vec<String>,
}

impl NumericParser {
    fn new(tokens: Vec<String>) -> Self {
        NumericParser {
            tokens,
            numeric_tokens: Vec::new(),
        }
    }

    fn extract_numeric(&mut self) -> Vec<String> {
        let re = Regex::new(r"^\d+(\.\d+)?$").unwrap();
        self.numeric_tokens = self.tokens.iter()
                                         .filter(|&&token| re.is_match(&token))
                                         .cloned()
                                         .collect();
        self.numeric_tokens.clone()
    }
}

struct PrecisionAnalyzer {
    numeric_tokens: Vec<String>,
}

impl PrecisionAnalyzer {
    fn new(numeric_tokens: Vec<String>) -> Self {
        PrecisionAnalyzer {
            numeric_tokens,
        }
    }

    fn analyze_precision(&self) -> HashMap<String, usize> {
        let mut precision = HashMap::new();
        for token in &self.numeric_tokens {
            if token.contains('.') {
                let parts: Vec<&str> = token.split('.').collect();
                precision.insert(token.clone(), parts[1].len());
            }
        }
        precision
    }
}

fn main() {
    let text = "The quick brown fox jumps over the lazy dog 123.456 789.10 100.001";
    let mut processor = TextProcessor::new(text);
    let tokens = processor.tokenize();
    let filtered_tokens = processor.filter_tokens();
    let mut parser = NumericParser::new(filtered_tokens);
    let numeric_tokens = parser.extract_numeric();
    let analyzer = PrecisionAnalyzer::new(numeric_tokens);
    let precision_results = analyzer.analyze_precision();
    println!("{:?}", precision_results);
}