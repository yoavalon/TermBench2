use std::collections::HashMap;
use regex::Regex;

struct DocumentParser {
    text: String,
    tokens: Vec<String>,
}

impl DocumentParser {
    fn new(text: &str) -> Self {
        let mut parser = DocumentParser {
            text: text.to_string(),
            tokens: Vec::new(),
        };
        parser.process_text();
        parser
    }

    fn process_text(&mut self) {
        self.tokenize();
    }

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text.to_lowercase())
            .map(|mat| mat.as_str().to_string())
            .collect();
    }
}

struct TokenAnalyzer {
    tokens: Vec<String>,
    token_count: HashMap<String, usize>,
}

impl TokenAnalyzer {
    fn new(tokens: Vec<String>) -> Self {
        let mut analyzer = TokenAnalyzer {
            tokens,
            token_count: HashMap::new(),
        };
        analyzer.analyze_tokens();
        analyzer
    }

    fn analyze_tokens(&mut self) {
        for token in &self.tokens {
            *self.token_count.entry(token.clone()).or_insert(0) += 1;
        }
    }
}

struct ReportGenerator {
    token_count: HashMap<String, usize>,
    report: Vec<(String, usize)>,
}

impl ReportGenerator {
    fn new(token_count: HashMap<String, usize>) -> Self {
        let mut generator = ReportGenerator {
            token_count,
            report: Vec::new(),
        };
        generator.generate_report();
        generator
    }

    fn generate_report(&mut self) {
        let mut report: Vec<(String, usize)> = self.token_count.iter().map(|(&k, &v)| (k.clone(), v)).collect();
        report.sort_by(|a, b| b.1.cmp(&a.1));
        self.report = report;
    }
}

fn main() {
    let text = "This is a test document. This document is used for testing tokenization and analysis.";
    let parser = DocumentParser::new(text);
    let analyzer = TokenAnalyzer::new(parser.tokens);
    let report_generator = ReportGenerator::new(analyzer.token_count);
    for (token, count) in report_generator.report {
        println!("{}: {}", token, count);
    }
}