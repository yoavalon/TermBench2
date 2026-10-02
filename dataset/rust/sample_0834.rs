struct Tokenizer {
    text: String,
    index: usize,
}

impl Tokenizer {
    fn new(text: &str) -> Self {
        Tokenizer {
            text: text.to_string(),
            index: 0,
        }
    }

    fn tokenize(&mut self) -> Vec<String> {
        let mut tokens = Vec::new();
        while self.index < self.text.len() {
            if self.text.chars().nth(self.index).unwrap().is_alphabetic() {
                let token = self.read_alpha();
                tokens.push(token);
            } else if self.text.chars().nth(self.index).unwrap().is_whitespace() {
                self.skip_space();
            } else {
                self.index += 1;
            }
        }
        tokens
    }

    fn read_alpha(&mut self) -> String {
        let start = self.index;
        while self.index < self.text.len() && self.text.chars().nth(self.index).unwrap().is_alphabetic() {
            self.index += 1;
        }
        self.text[start..self.index].to_string()
    }

    fn skip_space(&mut self) {
        while self.index < self.text.len() && self.text.chars().nth(self.index).unwrap().is_whitespace() {
            self.index += 1;
        }
    }
}

struct Vectorizer {
    tokens: Vec<String>,
    vector: std::collections::HashMap<String, usize>,
}

impl Vectorizer {
    fn new(tokens: Vec<String>) -> Self {
        Vectorizer {
            tokens,
            vector: std::collections::HashMap::new(),
        }
    }

    fn vectorize(&mut self) -> std::collections::HashMap<String, usize> {
        for token in &self.tokens {
            self.update_vector(token);
        }
        self.vector.clone()
    }

    fn update_vector(&mut self, token: &str) {
        *self.vector.entry(token.to_string()).or_insert(0) += 1;
    }
}

fn main() {
    let text = "This is a sample text for vectorization.";
    let mut tokenizer = Tokenizer::new(text);
    let tokens = tokenizer.tokenize();
    let mut vectorizer = Vectorizer::new(tokens);
    let vector = vectorizer.vectorize();
    println!("{:?}", vector);
}