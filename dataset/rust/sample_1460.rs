struct DocumentTokenizer {
    text: String,
    tokens: Vec<char>,
}

impl DocumentTokenizer {
    fn new(text: &str) -> DocumentTokenizer {
        DocumentTokenizer {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) {
        for char in self.text.chars() {
            if char.is_alphanumeric() || char.is_whitespace() {
                self.tokens.push(char);
            } else {
                self.tokens.push(' ');
            }
        }
    }

    fn filter_tokens(&mut self) {
        let mut filtered_tokens = Vec::new();
        let mut word = String::new();
        for token in &self.tokens {
            if token.is_alphanumeric() {
                word.push(*token);
            } else if token.is_whitespace() && !word.is_empty() {
                filtered_tokens.push(word.clone());
                word.clear();
            }
        }
        if !word.is_empty() {
            filtered_tokens.push(word);
        }
        self.tokens = filtered_tokens;
    }
}

struct DataMutator {
    tokenizer: DocumentTokenizer,
    tokens: Vec<String>,
}

impl DataMutator {
    fn new(tokenizer: DocumentTokenizer) -> DataMutator {
        DataMutator {
            tokenizer,
            tokens: Vec::new(),
        }
    }

    fn mutate(&mut self) {
        self.tokenizer.tokenize();
        self.tokenizer.filter_tokens();
        self.tokens = self.tokenizer.tokens.iter().map(|s| s.to_string()).collect();
    }
}

fn main() {
    let text = "Hello, world! This is a test.";
    let tokenizer = DocumentTokenizer::new(text);
    let mut mutator = DataMutator::new(tokenizer);
    mutator.mutate();
    for token in &mutator.tokens {
        print!("{}", token);
    }
}