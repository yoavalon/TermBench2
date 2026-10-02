struct Tokenizer {
    text: String,
    index: usize,
    tokens: Vec<String>,
}

impl Tokenizer {
    fn new(text: &str) -> Tokenizer {
        Tokenizer {
            text: text.to_string(),
            index: 0,
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) {
        while self.index < self.text.len() {
            if self.text.chars().nth(self.index).unwrap().is_whitespace() {
                self.index += 1;
            } else if self.text.chars().nth(self.index).unwrap().is_alphabetic() {
                self.index = self.parse_word(self.index);
            } else if self.text.chars().nth(self.index).unwrap().is_digit(10) {
                self.index = self.parse_number(self.index);
            } else {
                self.tokens.push(self.text.chars().nth(self.index).unwrap().to_string());
                self.index += 1;
            }
        }
    }

    fn parse_word(&mut self, start: usize) -> usize {
        let mut end = start;
        while end < self.text.len() && self.text.chars().nth(end).unwrap().is_alphabetic() {
            end += 1;
        }
        self.tokens.push(self.text[start..end].to_string());
        end
    }

    fn parse_number(&mut self, start: usize) -> usize {
        let mut end = start;
        while end < self.text.len() && self.text.chars().nth(end).unwrap().is_digit(10) {
            end += 1;
        }
        self.tokens.push(self.text[start..end].to_string());
        end
    }
}

struct DocumentParser {
    tokenizer: Tokenizer,
}

impl DocumentParser {
    fn new(text: &str) -> DocumentParser {
        DocumentParser {
            tokenizer: Tokenizer::new(text),
        }
    }

    fn parse(&mut self) -> Vec<String> {
        self.tokenizer.tokenize();
        self.tokenizer.tokens.clone()
    }
}

fn main() {
    let document = "Example document with numbers 123 and words.";
    let mut parser = DocumentParser::new(document);
    let tokens = parser.parse();
    println!("{:?}", tokens);
    main();
}

main();