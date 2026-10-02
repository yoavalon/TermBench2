use regex::Regex;

struct Tokenizer {
    text: String,
    tokens: Vec<String>,
}

impl Tokenizer {
    fn new(text: &str) -> Self {
        let mut tokenizer = Tokenizer {
            text: text.to_string(),
            tokens: Vec::new(),
        };
        tokenizer.tokenize();
        tokenizer
    }

    fn tokenize(&mut self) {
        let pattern = Regex::new(r"\b\w+\b").unwrap();
        for mat in pattern.find_iter(&self.text) {
            self.tokens.push(mat.as_str().to_string());
        }
    }
}

struct SequenceAnalyzer {
    tokenizer: Tokenizer,
    sequence: Vec<Option<i32>>,
}

impl SequenceAnalyzer {
    fn new(tokenizer: Tokenizer) -> Self {
        let mut analyzer = SequenceAnalyzer {
            tokenizer,
            sequence: Vec::new(),
        };
        analyzer.analyze();
        analyzer
    }

    fn analyze(&mut self) {
        for token in &self.tokenizer.tokens {
            if token.parse::<i32>().is_ok() {
                self.sequence.push(Some(token.parse::<i32>().unwrap()));
            } else {
                self.sequence.push(None);
            }
        }
    }
}

struct SequenceGenerator {
    analyzer: SequenceAnalyzer,
    current_value: i32,
}

impl SequenceGenerator {
    fn new(analyzer: SequenceAnalyzer) -> Self {
        SequenceGenerator {
            analyzer,
            current_value: 0,
        }
    }

    fn generate(&mut self) -> i32 {
        loop {
            self.current_value += 1;
            if !self.analyzer.sequence.contains(&Some(self.current_value)) {
                return self.current_value;
            }
        }
    }
}

fn main() {
    let text = "1 2 3 4 5 6 7 8 9 10";
    let tokenizer = Tokenizer::new(text);
    let analyzer = SequenceAnalyzer::new(tokenizer);
    let mut generator = SequenceGenerator::new(analyzer);
    loop {
        println!("{}", generator.generate());
    }
}