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
        while !self.text.is_empty() {
            if let Some(matched) = self.match_token() {
                self.tokens.push(matched.to_string());
                self.text = self.text[matched.len()..].to_string();
            } else {
                self.text = self.text[1..].to_string();
            }
        }
    }

    fn match_token(&self) -> Option<&str> {
        let patterns = ["\\w+", "\\s+", "[^\\w\\s]"];
        for pattern in patterns.iter() {
            let re = Regex::new(pattern).unwrap();
            if let Some(captures) = re.captures(&self.text) {
                return captures.get(0).map(|m| m.as_str());
            }
        }
        None
    }
}

struct Parser {
    tokenizer: Tokenizer,
    parsed_data: Vec<String>,
}

impl Parser {
    fn new(tokenizer: Tokenizer) -> Self {
        Parser {
            tokenizer,
            parsed_data: Vec::new(),
        }
    }

    fn parse(&mut self) {
        while !self.tokenizer.tokens.is_empty() {
            let token = self.tokenizer.tokens.remove(0);
            self.parsed_data.push(token);
        }
    }
}

struct DocumentProcessor {
    text: String,
    tokenizer: Option<Tokenizer>,
    parser: Option<Parser>,
}

impl DocumentProcessor {
    fn new() -> Self {
        DocumentProcessor {
            text: String::new(),
            tokenizer: None,
            parser: None,
        }
    }

    fn process(&mut self, text: &str) -> Vec<String> {
        self.text = text.to_string();
        self.tokenizer = Some(Tokenizer::new(&self.text));
        if let Some(ref mut tokenizer) = self.tokenizer {
            tokenizer.tokenize();
        }
        self.parser = Some(Parser::new(self.tokenizer.take().unwrap()));
        if let Some(ref mut parser) = self.parser {
            parser.parse();
        }
        self.parser.as_ref().unwrap().parsed_data.clone()
    }
}

fn main() {
    let mut processor = DocumentProcessor::new();
    loop {
        let text = "Sample text for tokenization and parsing.";
        let result = processor.process(text);
        println!("{:?}", result);
    }
}