use regex::Regex;

struct DocumentTokenizer {
    text: String,
    tokens: Vec<String>,
}

impl DocumentTokenizer {
    fn new(text: &str) -> Self {
        DocumentTokenizer {
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

struct BoundaryConditionChecker {
    tokens: Vec<String>,
    max_length: usize,
    long_tokens: Vec<String>,
}

impl BoundaryConditionChecker {
    fn new(tokens: Vec<String>, max_length: usize) -> Self {
        BoundaryConditionChecker {
            tokens,
            max_length,
            long_tokens: Vec::new(),
        }
    }

    fn check_conditions(&mut self) {
        for token in &self.tokens {
            if token.len() > self.max_length {
                self.long_tokens.push(token.clone());
            }
        }
    }

    fn get_long_tokens(&self) -> &Vec<String> {
        &self.long_tokens
    }
}

struct ReportGenerator {
    long_tokens: Vec<String>,
    report: String,
}

impl ReportGenerator {
    fn new(long_tokens: Vec<String>) -> Self {
        ReportGenerator {
            long_tokens,
            report: String::new(),
        }
    }

    fn generate_report(&mut self) {
        if !self.long_tokens.is_empty() {
            self.report = format!("Tokens exceeding {} characters: {}", self.long_tokens[0].len(), self.long_tokens.join(", "));
        } else {
            self.report = "No tokens exceed the boundary condition.".to_string();
        }
    }

    fn get_report(&self) -> &str {
        &self.report
    }
}

fn main() {
    let text = "This is a simple text to demonstrate the boundary conditions of tokenization in Python.";
    let mut tokenizer = DocumentTokenizer::new(text);
    tokenizer.tokenize();
    let tokens = tokenizer.get_tokens().clone();
    let mut boundary_checker = BoundaryConditionChecker::new(tokens, 10);
    boundary_checker.check_conditions();
    let long_tokens = boundary_checker.get_long_tokens().clone();
    let mut report_generator = ReportGenerator::new(long_tokens);
    report_generator.generate_report();
    println!("{}", report_generator.get_report());
}