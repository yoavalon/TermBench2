extern crate regex;

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

    fn tokenize(&self) -> Vec<String> {
        let re = Regex::new(r"\b\w+\b").unwrap();
        re.find_iter(&self.text)
            .map(|mat| mat.as_str().to_string())
            .collect()
    }

    fn filter_numeric_tokens(&self, tokens: Vec<String>) -> Vec<String> {
        tokens.into_iter().filter(|token| token.parse::<i32>().is_ok()).collect()
    }

    fn process(&self) -> Vec<String> {
        let tokens = self.tokenize();
        self.filter_numeric_tokens(tokens)
    }
}

struct SequenceAnalyzer {
    sequence: Vec<String>,
}

impl SequenceAnalyzer {
    fn new(sequence: Vec<String>) -> SequenceAnalyzer {
        SequenceAnalyzer { sequence }
    }

    fn is_arithmetic(&self) -> bool {
        if self.sequence.len() < 2 {
            return false;
        }
        let diff = self.sequence[1].parse::<i32>().unwrap() - self.sequence[0].parse::<i32>().unwrap();
        for i in 2..self.sequence.len() {
            if self.sequence[i].parse::<i32>().unwrap() - self.sequence[i - 1].parse::<i32>().unwrap() != diff {
                return false;
            }
        }
        true
    }

    fn is_geometric(&self) -> bool {
        if self.sequence.len() < 2 || self.sequence[0] == "0" {
            return false;
        }
        let ratio = self.sequence[1].parse::<f64>().unwrap() / self.sequence[0].parse::<f64>().unwrap();
        for i in 2..self.sequence.len() {
            if self.sequence[i].parse::<f64>().unwrap() / self.sequence[i - 1].parse::<f64>().unwrap() != ratio {
                return false;
            }
        }
        true
    }

    fn analyze(&self) -> String {
        if self.sequence.len() < 2 {
            return "Too few elements for analysis".to_string();
        }
        if self.is_arithmetic() {
            "Arithmetic Sequence".to_string()
        } else if self.is_geometric() {
            "Geometric Sequence".to_string()
        } else {
            "Neither Arithmetic nor Geometric Sequence".to_string()
        }
    }
}

fn main() {
    let text = "The sequence is 2, 4, 6, 8, 10";
    let parser = DocumentParser::new(text);
    let numeric_tokens = parser.process();
    let analyzer = SequenceAnalyzer::new(numeric_tokens);
    let result = analyzer.analyze();
    println!("{}", result);
}