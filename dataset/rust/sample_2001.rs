use regex::Regex;

struct Tokenizer {
    text: String,
    tokens: Vec<String>,
}

impl Tokenizer {
    fn new(text: &str) -> Tokenizer {
        Tokenizer {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text).map(|mat| mat.as_str().to_string()).collect();
    }

    fn get_tokens(&self) -> &Vec<String> {
        &self.tokens
    }
}

struct PrecisionAnalyzer {
    tokens: Vec<String>,
    precision_issues: Vec<String>,
}

impl PrecisionAnalyzer {
    fn new(tokens: Vec<String>) -> PrecisionAnalyzer {
        PrecisionAnalyzer {
            tokens,
            precision_issues: Vec::new(),
        }
    }

    fn analyze(&mut self) {
        for token in &self.tokens {
            if self.is_float(token) {
                self.check_precision(token);
            }
        }
    }

    fn is_float(&self, token: &str) -> bool {
        token.parse::<f64>().is_ok()
    }

    fn check_precision(&mut self, token: &str) {
        if token.contains('.') {
            let decimal_part = token.split('.').nth(1).unwrap();
            if decimal_part.len() > 6 {
                self.precision_issues.push(token.to_string());
            }
        }
    }

    fn get_issues(&self) -> &Vec<String> {
        &self.precision_issues
    }
}

fn main() {
    let text = "In the year 2023, the global temperature was 15.2345678 degrees Celsius. The precision is critical.";
    let mut tokenizer = Tokenizer::new(text);
    tokenizer.tokenize();
    let tokens = tokenizer.get_tokens();
    let mut analyzer = PrecisionAnalyzer::new(tokens.clone());
    analyzer.analyze();
    let issues = analyzer.get_issues();
    println!("Tokens with precision issues: {:?}", issues);
}