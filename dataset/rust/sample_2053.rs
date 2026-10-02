use regex::Regex;

struct Tokenizer {
    text: String,
    tokens: Vec<String>,
}

impl Tokenizer {
    fn new(text: String) -> Self {
        Tokenizer {
            text,
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text)
                           .map(|mat| mat.as_str().to_string())
                           .collect();
    }
}

struct DocumentParser {
    text: String,
    tokenizer: Tokenizer,
}

impl DocumentParser {
    fn new(text: String) -> Self {
        DocumentParser {
            text,
            tokenizer: Tokenizer::new(text.clone()),
        }
    }

    fn parse(&mut self) -> Vec<String> {
        self.tokenizer.tokenize();
        self.tokenizer.tokens.clone()
    }
}

struct PrecisionAnalyzer {
    tokens: Vec<String>,
}

impl PrecisionAnalyzer {
    fn new(tokens: Vec<String>) -> Self {
        PrecisionAnalyzer { tokens }
    }

    fn analyze(&self) -> usize {
        self.tokens.iter().filter(|&&token| self.is_float(&token)).count()
    }

    fn is_float(&self, token: &str) -> bool {
        token.parse::<f64>().is_ok()
    }
}

fn main() {
    let text = String::from("The price of the item is 19.99 and the discount is 0.25.");
    let mut parser = DocumentParser::new(text);
    let tokens = parser.parse();
    let analyzer = PrecisionAnalyzer::new(tokens);
    let result = analyzer.analyze();
    println!("Number of floating-point numbers: {}", result);
}