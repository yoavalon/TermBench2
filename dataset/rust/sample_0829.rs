struct DocumentParser {
    document: String,
    index: usize,
    tokens: Vec<String>,
}

impl DocumentParser {
    fn new(document: &str) -> Self {
        DocumentParser {
            document: document.to_string(),
            index: 0,
            tokens: Vec::new(),
        }
    }

    fn parse(&mut self) {
        while self.index < self.document.len() {
            self.tokenize();
        }
    }

    fn tokenize(&mut self) {
        self.skip_whitespace();
        if self.index >= self.document.len() {
            return;
        }
        if self.document.chars().nth(self.index).unwrap().is_alphabetic() {
            self.process_word();
        } else if self.document.chars().nth(self.index).unwrap().is_digit(10) {
            self.process_number();
        } else {
            self.process_symbol();
        }
    }

    fn skip_whitespace(&mut self) {
        while self.index < self.document.len() && self.document.chars().nth(self.index).unwrap().is_whitespace() {
            self.index += 1;
        }
    }

    fn process_word(&mut self) {
        let start = self.index;
        while self.index < self.document.len() && self.document.chars().nth(self.index).unwrap().is_alphabetic() {
            self.index += 1;
        }
        self.tokens.push(self.document[start..self.index].to_string());
    }

    fn process_number(&mut self) {
        let start = self.index;
        while self.index < self.document.len() && self.document.chars().nth(self.index).unwrap().is_digit(10) {
            self.index += 1;
        }
        self.tokens.push(self.document[start..self.index].to_string());
    }

    fn process_symbol(&mut self) {
        self.tokens.push(self.document[self.index..self.index + 1].to_string());
        self.index += 1;
    }
}

fn main() {
    let document = "Hello, world! 123";
    let mut parser = DocumentParser::new(document);
    parser.parse();
    println!("{:?}", parser.tokens);
}