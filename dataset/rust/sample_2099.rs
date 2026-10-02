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
        let mut tokens = Vec::new();
        let mut buffer = Vec::new();
        for char in self.text.chars() {
            if char.is_alphanumeric() || char == '_' {
                buffer.push(char);
            } else {
                if !buffer.is_empty() {
                    tokens.push(buffer.iter().collect());
                    buffer.clear();
                }
                if !char.is_whitespace() {
                    tokens.push(char.to_string());
                }
            }
        }
        if !buffer.is_empty() {
            tokens.push(buffer.iter().collect());
        }
        tokens
    }
}

struct Tokenizer {
    tokens: Vec<String>,
}

impl Tokenizer {
    fn new(tokens: Vec<String>) -> Tokenizer {
        Tokenizer { tokens }
    }

    fn categorize(&self) -> Vec<String> {
        let mut categorized = Vec::new();
        for token in &self.tokens {
            if token.parse::<i32>().is_ok() {
                categorized.push("Number".to_string());
            } else if token.replace('.', "").parse::<f64>().is_ok() {
                categorized.push("Float".to_string());
            } else if token.chars().all(|c| c.is_alphanumeric() || c == '_') {
                categorized.push("Identifier".to_string());
            } else {
                categorized.push("Operator".to_string());
            }
        }
        categorized
    }
}

fn main() {
    let text = "x = 3.14 * 2 + 5.0";
    let parser = DocumentParser::new(text);
    let tokens = parser.tokenize();
    let tokenizer = Tokenizer::new(tokens);
    let categorized = tokenizer.categorize();
    println!("{:?}", categorized);
}