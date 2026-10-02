use regex::Regex;

struct Tokenizer {
    text: String,
    tokens: Vec<String>,
}

impl Tokenizer {
    fn new(text: &str) -> Self {
        Tokenizer {
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

struct DocumentParser {
    text: String,
    tokenizer: Tokenizer,
}

impl DocumentParser {
    fn new(text: &str) -> Self {
        DocumentParser {
            text: text.to_string(),
            tokenizer: Tokenizer::new(text),
        }
    }

    fn parse(&mut self) {
        self.tokenizer.tokenize();
    }

    fn get_parsed_tokens(&self) -> &Vec<String> {
        self.tokenizer.get_tokens()
    }
}

struct AnalysisEngine {
    tokens: Vec<String>,
}

impl AnalysisEngine {
    fn new(tokens: Vec<String>) -> Self {
        AnalysisEngine { tokens }
    }

    fn analyze(&self) -> Vec<String> {
        let re = Regex::new(r"^\d+\.\d+$").unwrap();
        self.tokens.iter()
                 .filter(|&token| re.is_match(token))
                 .cloned()
                 .collect()
    }
}

fn main() {
    let text = "In this document, we have 3.14 and 2.71828 as floating point numbers.";
    let mut parser = DocumentParser::new(text);
    parser.parse();
    let tokens = parser.get_parsed_tokens().clone();
    let analyzer = AnalysisEngine::new(tokens);
    let float_tokens = analyzer.analyze();
    println!("Floating point tokens: {:?}", float_tokens);
}