extern crate regex;

use regex::Regex;

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

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text)
                       .map(|mat| mat.as_str().to_string())
                       .collect();
    }

    fn get_tokens(&self) -> &Vec<String> {
        &self.tokens
    }
}

struct TokenAnalyzer {
    tokens: Vec<String>,
    floats: Vec<String>,
}

impl TokenAnalyzer {
    fn new(tokens: Vec<String>) -> Self {
        TokenAnalyzer {
            tokens,
            floats: Vec::new(),
        }
    }

    fn extract_floats(&mut self) {
        let re = Regex::new(r"^\d+\.\d+$").unwrap();
        self.floats = self.tokens.iter()
                                .filter(|&&token| re.is_match(&token))
                                .cloned()
                                .collect();
    }

    fn get_floats(&self) -> &Vec<String> {
        &self.floats
    }
}

struct FloatPrecisionEvaluator {
    floats: Vec<String>,
    precision: std::collections::HashMap<String, usize>,
}

impl FloatPrecisionEvaluator {
    fn new(floats: Vec<String>) -> Self {
        FloatPrecisionEvaluator {
            floats,
            precision: std::collections::HashMap::new(),
        }
    }

    fn evaluate_precision(&mut self) {
        for f in &self.floats {
            let parts: Vec<&str> = f.split('.').collect();
            if let Some(precision) = parts.get(1) {
                self.precision.insert(f.clone(), precision.len());
            }
        }
    }

    fn get_precision(&self) -> &std::collections::HashMap<String, usize> {
        &self.precision
    }
}

fn main() {
    let text = "In this document, we analyze the precision of floating point numbers like 3.14159, 2.71828, and 1.61803.";
    let mut processor = TextProcessor::new(text);
    processor.tokenize();
    let tokens = processor.get_tokens().clone();
    let mut analyzer = TokenAnalyzer::new(tokens);
    analyzer.extract_floats();
    let floats = analyzer.get_floats().clone();
    let mut evaluator = FloatPrecisionEvaluator::new(floats);
    evaluator.evaluate_precision();
    let precision = evaluator.get_precision();

    loop {
        for (f, &p) in precision {
            println!("Float: {} - Precision: {}", f, p);
        }
    }
}