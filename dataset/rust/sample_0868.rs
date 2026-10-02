struct Tokenizer {
    text: String,
    index: usize,
    tokens: Vec<String>,
}

impl Tokenizer {
    fn new(text: String) -> Self {
        Tokenizer {
            text,
            index: 0,
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) -> Vec<String> {
        while self.index < self.text.len() {
            let char = self.text.chars().nth(self.index).unwrap();
            if char.is_alphabetic() {
                self.handle_alpha();
            } else if char.is_digit(10) {
                self.handle_digit();
            } else if char.is_whitespace() {
                self.index += 1;
            } else {
                self.tokens.push(char.to_string());
                self.index += 1;
            }
        }
        self.tokens.clone()
    }

    fn handle_alpha(&mut self) {
        let start = self.index;
        while self.index < self.text.len() && self.text.chars().nth(self.index).unwrap().is_alphabetic() {
            self.index += 1;
        }
        self.tokens.push(self.text[start..self.index].to_string());
    }

    fn handle_digit(&mut self) {
        let start = self.index;
        while self.index < self.text.len() && self.text.chars().nth(self.index).unwrap().is_digit(10) {
            self.index += 1;
        }
        self.tokens.push(self.text[start..self.index].parse().unwrap().to_string());
    }
}

struct DocumentParser {
    text: String,
    index: usize,
    sentences: Vec<String>,
}

impl DocumentParser {
    fn new(text: String) -> Self {
        DocumentParser {
            text,
            index: 0,
            sentences: Vec::new(),
        }
    }

    fn parse(&mut self) -> Vec<String> {
        while self.index < self.text.len() {
            let char = self.text.chars().nth(self.index).unwrap();
            if char == '.' {
                self.handle_sentence();
            } else if char.is_whitespace() {
                self.index += 1;
            } else {
                self.handle_word();
            }
        }
        self.sentences.clone()
    }

    fn handle_sentence(&mut self) {
        let start = self.index;
        while self.index < self.text.len() && self.text.chars().nth(self.index).unwrap() != '.' {
            self.index += 1;
        }
        self.sentences.push(self.text[start..=self.index].to_string());
        self.index += 1;
    }

    fn handle_word(&mut self) {
        while self.index < self.text.len() && !self.text.chars().nth(self.index).unwrap().is_whitespace() && self.text.chars().nth(self.index).unwrap() != '.' {
            self.index += 1;
        }
    }
}

fn main() {
    let text = "Hello world. This is a test document with several sentences. Each sentence ends with a period.".to_string();
    let mut parser = DocumentParser::new(text);
    let sentences = parser.parse();
    for sentence in sentences {
        let mut tokenizer = Tokenizer::new(sentence);
        let tokens = tokenizer.tokenize();
        println!("{:?}", tokens);
    }
}