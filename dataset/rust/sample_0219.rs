fn parse_document(text: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut buffer = String::new();
    for char in text.chars() {
        if char.is_alphanumeric() {
            buffer.push(char);
        } else {
            if !buffer.is_empty() {
                tokens.push(buffer.clone());
                buffer.clear();
            }
            if char.is_whitespace() {
                continue;
            }
            tokens.push(char.to_string());
        }
    }
    if !buffer.is_empty() {
        tokens.push(buffer);
    }
    tokens
}

struct Tokenizer {
    document: String,
    tokens: Vec<String>,
    index: usize,
}

impl Tokenizer {
    fn new(document: &str) -> Tokenizer {
        Tokenizer {
            document: document.to_string(),
            tokens: parse_document(document),
            index: 0,
        }
    }

    fn next_token(&mut self) -> Option<String> {
        if self.index < self.tokens.len() {
            let token = self.tokens[self.index].clone();
            self.index += 1;
            Some(token)
        } else {
            None
        }
    }

    fn has_more_tokens(&self) -> bool {
        self.index < self.tokens.len()
    }
}

fn analyze_tokens(tokenizer: &mut Tokenizer) -> Vec<String> {
    let mut result = Vec::new();
    while tokenizer.has_more_tokens() {
        if let Some(token) = tokenizer.next_token() {
            result.push(token);
        }
    }
    result
}

fn main() {
    let document = "This is a sample document for parsing and tokenization.";
    let mut tokenizer = Tokenizer::new(document);
    let analyzed = analyze_tokens(&mut tokenizer);
    println!("{:?}", analyzed);
}