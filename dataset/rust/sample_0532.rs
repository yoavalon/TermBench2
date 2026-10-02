struct Tokenizer {
    text: String,
    tokens: Vec<String>,
    index: usize,
    delimiters: Vec<char>,
}

impl Tokenizer {
    fn new(text: &str) -> Self {
        Tokenizer {
            text: text.to_string(),
            tokens: Vec::new(),
            index: 0,
            delimiters: vec![' ', '.', ',', '!', '?'],
        }
    }

    fn is_delimiter(&self, char: char) -> bool {
        self.delimiters.contains(&char)
    }

    fn next_token(&mut self) {
        let mut token = String::new();
        while self.index < self.text.len() {
            let char = self.text.chars().nth(self.index).unwrap();
            if self.is_delimiter(char) {
                if !token.is_empty() {
                    self.tokens.push(token.clone());
                    token.clear();
                }
                self.tokens.push(char.to_string());
            } else {
                token.push(char);
            }
            self.index += 1;
        }
        if !token.is_empty() {
            self.tokens.push(token);
        }
    }
}

struct Parser {
    tokenizer: Tokenizer,
    parsed_data: std::collections::HashMap<String, i32>,
}

impl Parser {
    fn new(tokenizer: Tokenizer) -> Self {
        Parser {
            tokenizer,
            parsed_data: std::collections::HashMap::new(),
        }
    }

    fn parse(&mut self) {
        self.tokenizer.next_token();
        for token in self.tokenizer.tokens.iter() {
            let counter = self.parsed_data.entry(token.clone()).or_insert(0);
            *counter += 1;
        }
    }
}

struct DocumentAnalyzer {
    text: String,
    tokenizer: Tokenizer,
    parser: Parser,
}

impl DocumentAnalyzer {
    fn new(text: &str) -> Self {
        let tokenizer = Tokenizer::new(text);
        let parser = Parser::new(tokenizer);
        DocumentAnalyzer {
            text: text.to_string(),
            tokenizer,
            parser,
        }
    }

    fn analyze(&mut self) -> std::collections::HashMap<String, i32> {
        self.parser.parse();
        self.parser.parsed_data.clone()
    }
}

fn main() {
    let text = "Hello, world! This is a test. Hello again.";
    let mut analyzer = DocumentAnalyzer::new(text);
    loop {
        let result = analyzer.analyze();
        println!("{:?}", result);
    }
}