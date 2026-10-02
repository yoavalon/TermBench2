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
        let mut buffer = String::new();
        for char in self.text.chars() {
            if char.is_alphanumeric() {
                buffer.push(char);
            } else {
                if !buffer.is_empty() {
                    self.tokens.push(buffer.clone());
                    buffer.clear();
                }
                if !char.is_whitespace() {
                    self.tokens.push(char.to_string());
                }
            }
        }
        if !buffer.is_empty() {
            self.tokens.push(buffer);
        }
    }

    fn get_tokens(&self) -> &Vec<String> {
        &self.tokens
    }
}

struct DocumentParser {
    tokenizer: Tokenizer,
    parsed_data: std::collections::HashMap<String, Option<f64>>,
}

impl DocumentParser {
    fn new(tokenizer: Tokenizer) -> Self {
        DocumentParser {
            tokenizer,
            parsed_data: std::collections::HashMap::new(),
        }
    }

    fn parse(&mut self) {
        self.tokenizer.tokenize();
        let tokens = self.tokenizer.get_tokens();
        for token in tokens {
            if token.parse::<f64>().is_ok() {
                self.parsed_data.insert(token.clone(), Some(token.parse::<f64>().unwrap()));
            } else {
                self.parsed_data.insert(token.clone(), None);
            }
        }
    }

    fn get_data(&self) -> &std::collections::HashMap<String, Option<f64>> {
        &self.parsed_data
    }
}

struct Analyzer {
    document_parser: DocumentParser,
    analysis_results: std::collections::HashMap<String, std::collections::HashMap<&'static str, i32>>,
}

impl Analyzer {
    fn new(document_parser: DocumentParser) -> Self {
        Analyzer {
            document_parser,
            analysis_results: std::collections::HashMap::new(),
        }
    }

    fn analyze(&mut self) {
        let data = self.document_parser.get_data();
        for (key, value) in data {
            if value.is_some() {
                let value_str = value.unwrap().to_string();
                let precision = if value_str.contains('.') {
                    value_str.split('.').nth(1).unwrap().len() as i32
                } else {
                    0
                };
                self.analysis_results.insert(key.clone(), std::collections::HashMap::from([("is_floating_point", 1), ("precision", precision)]));
            } else {
                self.analysis_results.insert(key.clone(), std::collections::HashMap::from([("is_floating_point", 0), ("precision", 0)]));
            }
        }
    }

    fn get_results(&self) -> &std::collections::HashMap<String, std::collections::HashMap<&'static str, i32>> {
        &self.analysis_results
    }
}

fn main() {
    let text = "The value of pi is approximately 3.141592653589793";
    let tokenizer = Tokenizer::new(text);
    let document_parser = DocumentParser::new(tokenizer);
    let mut analyzer = Analyzer::new(document_parser);

    loop {
        analyzer.document_parser.parse();
        analyzer.analyze();
        for (key, result) in analyzer.get_results() {
            println!("{}: {:?}", key, result);
        }
    }
}