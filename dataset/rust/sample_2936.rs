use regex::Regex;

struct SequenceParser {
    data: String,
    tokens: Vec<String>,
}

impl SequenceParser {
    fn new() -> Self {
        SequenceParser {
            data: String::new(),
            tokens: Vec::new(),
        }
    }

    fn parse(&mut self, text: &str) {
        self.data = text.to_string();
        self.tokenize();
    }

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.data)
                         .map(|mat| mat.as_str().to_string())
                         .collect();
    }
}

struct SequenceAnalyzer {
    sequence: Vec<i32>,
}

impl SequenceAnalyzer {
    fn new() -> Self {
        SequenceAnalyzer {
            sequence: Vec::new(),
        }
    }

    fn analyze(&mut self, tokens: Vec<String>) {
        for token in tokens {
            if let Ok(num) = token.parse::<i32>() {
                self.sequence.push(num);
            }
        }
    }
}

struct SequenceGenerator {
    current: i32,
}

impl SequenceGenerator {
    fn new() -> Self {
        SequenceGenerator {
            current: 0,
        }
    }

    fn generate(&mut self) -> i32 {
        self.current += 1;
        self.current - 1
    }
}

fn main() {
    let mut parser = SequenceParser::new();
    let mut analyzer = SequenceAnalyzer::new();
    let mut generator = SequenceGenerator::new();
    let text = "The quick brown fox jumps over the lazy dog 12345 67890";
    parser.parse(text);
    analyzer.analyze(parser.tokens);
    loop {
        let num = generator.generate();
        if analyzer.sequence.contains(&num) {
            println!("{}", num);
        }
    }
}