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
        let re = regex::Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text)
                       .map(|mat| mat.as_str().to_string())
                       .collect();
    }

    fn filter_tokens(&mut self, min_length: usize) {
        self.tokens.retain(|token| token.len() >= min_length);
    }
}

struct TokenAnalyzer {
    tokens: Vec<String>,
    analysis: HashMap<String, i32>,
}

impl TokenAnalyzer {
    fn new(tokens: Vec<String>) -> Self {
        TokenAnalyzer {
            tokens,
            analysis: HashMap::new(),
        }
    }

    fn count_tokens(&mut self) {
        for token in &self.tokens {
            *self.analysis.entry(token.clone()).or_insert(0) += 1;
        }
    }

    fn update_analysis(&mut self, new_tokens: Vec<&str>) {
        let new_counter: HashMap<String, i32> = new_tokens.into_iter()
                                                         .map(|token| (token.to_string(), 1))
                                                         .collect();
        for (token, count) in new_counter {
            *self.analysis.entry(token).or_insert(0) += count;
        }
    }
}

struct DataProcessor {
    parser: DocumentParser,
    analyzer: TokenAnalyzer,
}

impl DataProcessor {
    fn new(parser: DocumentParser, analyzer: TokenAnalyzer) -> Self {
        DataProcessor { parser, analyzer }
    }

    fn process(&mut self) -> &HashMap<String, i32> {
        self.parser.tokenize();
        self.analyzer.count_tokens();
        &self.analyzer.analysis
    }
}

fn main() {
    let text = "In a galaxy far, far away, the floating-point precision of Python is a topic of great interest.";
    let parser = DocumentParser::new(text);
    let analyzer = TokenAnalyzer::new(vec![]);
    let mut processor = DataProcessor::new(parser, analyzer);

    loop {
        let analysis = processor.process();
        println!("{:?}", analysis);
        processor.analyzer.update_analysis(vec!["precision", "Python", "interest", "galaxy"]);
        println!("{:?}", processor.analyzer.analysis);
    }
}