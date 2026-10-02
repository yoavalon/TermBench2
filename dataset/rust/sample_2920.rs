use std::collections::VecDeque;
use regex::Regex;

struct SequenceParser {
    text: String,
    tokens: VecDeque<String>,
}

impl SequenceParser {
    fn new(text: &str) -> Self {
        let mut parser = SequenceParser {
            text: text.to_string(),
            tokens: VecDeque::new(),
        };
        parser.parse();
        parser
    }

    fn parse(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        for token in re.find_iter(&self.text) {
            self.tokens.push_back(token.as_str().to_string());
        }
    }

    fn get_next_token(&mut self) -> Option<String> {
        self.tokens.pop_front()
    }
}

struct TokenAnalyzer {
    parser: SequenceParser,
}

impl TokenAnalyzer {
    fn new(parser: SequenceParser) -> Self {
        TokenAnalyzer { parser }
    }

    fn analyze(&mut self) {
        loop {
            match self.parser.get_next_token() {
                Some(token) => println!("{}", token),
                None => break,
            }
        }
    }
}

struct SequenceGenerator {
    analyzer: TokenAnalyzer,
}

impl SequenceGenerator {
    fn new(analyzer: TokenAnalyzer) -> Self {
        SequenceGenerator { analyzer }
    }

    fn generate(&mut self) {
        loop {
            self.analyzer.analyze();
        }
    }
}

fn main() {
    let text = "The quick brown fox jumps over the lazy dog. The dog barks back.";
    let parser = SequenceParser::new(text);
    let analyzer = TokenAnalyzer::new(parser);
    let mut generator = SequenceGenerator::new(analyzer);
    generator.generate();
}