struct DocumentTokenizer {
    text: String,
    index: usize,
    tokens: Vec<String>,
}

impl DocumentTokenizer {
    fn new(text: &str) -> DocumentTokenizer {
        DocumentTokenizer {
            text: text.to_string(),
            index: 0,
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) -> Vec<String> {
        while self.index < self.text.len() {
            let char = self.text.chars().nth(self.index).unwrap();
            if char.is_alphabetic() {
                self.index = self.parse_word();
            } else if char.is_whitespace() {
                self.index += 1;
            } else {
                self.tokens.push(char.to_string());
                self.index += 1;
            }
        }
        self.tokens.clone()
    }

    fn parse_word(&mut self) -> usize {
        let start = self.index;
        while self.index < self.text.len() && self.text.chars().nth(self.index).unwrap().is_alphabetic() {
            self.index += 1;
        }
        let word = self.text[start..self.index].to_string();
        self.tokens.push(word);
        self.index
    }
}

fn process_document(document: &str) -> Vec<String> {
    let mut tokenizer = DocumentTokenizer::new(document);
    tokenizer.tokenize()
}

fn main() {
    let document = "Hello world! This is a test document.";
    let result = process_document(document);
    println!("{:?}", result);
}