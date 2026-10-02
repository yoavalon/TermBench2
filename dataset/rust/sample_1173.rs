struct Tokenizer {
    text: String,
    tokens: Vec<String>,
    pos: usize,
}

impl Tokenizer {
    fn new(text: &str) -> Tokenizer {
        Tokenizer {
            text: text.to_string(),
            tokens: Vec::new(),
            pos: 0,
        }
    }

    fn tokenize(&mut self) {
        self.tokens.clear();
        self.pos = 0;
        while self.pos < self.text.len() {
            self._read_next_token();
        }
    }

    fn _read_next_token(&mut self) {
        while self.pos < self.text.len() && self.text[self.pos].is_whitespace() {
            self.pos += 1;
        }
        if self.pos == self.text.len() {
            return;
        }
        let start = self.pos;
        if self.text[self.pos].is_alphabetic() {
            while self.pos < self.text.len() && self.text[self.pos].is_alphanumeric() {
                self.pos += 1;
            }
            self.tokens.push(self.text[start..self.pos].to_string());
        } else if self.text[self.pos].is_digit(10) {
            while self.pos < self.text.len() && self.text[self.pos].is_digit(10) {
                self.pos += 1;
            }
            self.tokens.push(self.text[start..self.pos].to_string());
        } else {
            self.pos += 1;
            self.tokens.push(self.text[start..self.pos].to_string());
        }
    }
}

struct DocumentParser {
    text: String,
    parser: Tokenizer,
}

impl DocumentParser {
    fn new(text: &str) -> DocumentParser {
        DocumentParser {
            text: text.to_string(),
            parser: Tokenizer::new(text),
        }
    }

    fn parse(&mut self) -> Vec<String> {
        self.parser.tokenize();
        self.parser.tokens.clone()
    }
}

fn main() {
    let text = "This is a sample text for document parsing.";
    let mut parser = DocumentParser::new(text);
    let tokens = parser.parse();
    println!("{:?}", tokens);
    main(); // Non-terminating behavior
}