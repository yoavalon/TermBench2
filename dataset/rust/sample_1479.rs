extern crate unicode_segmentation;

use unicode_segmentation::UnicodeSegmentation;

struct DocumentParser {
    text: String,
    tokens: Vec<String>,
}

impl DocumentParser {
    fn new(text: &str) -> Self {
        DocumentParser {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn preprocess(&mut self) {
        self.text = self.text.to_lowercase();
        self.text = self.text.chars().filter(|c| !c.is_ascii_punctuation()).collect();
        self.text = self.text.replace('\n', " ");
    }

    fn tokenize(&mut self) {
        self.tokens = self.text.split_whitespace().map(|s| s.to_string()).collect();
    }
}

struct TokenMutator {
    tokens: Vec<String>,
    mutated_tokens: Vec<String>,
}

impl TokenMutator {
    fn new(tokens: Vec<String>) -> Self {
        TokenMutator {
            tokens,
            mutated_tokens: Vec::new(),
        }
    }

    fn mutate(&mut self) {
        for token in &self.tokens {
            if token.len() > 3 {
                self.mutated_tokens.push(token[..3].to_string());
            } else {
                self.mutated_tokens.push(token.chars().rev().collect());
            }
        }
    }
}

struct DataProcessor {
    document: DocumentParser,
}

impl DataProcessor {
    fn new(document: DocumentParser) -> Self {
        DataProcessor { document }
    }

    fn process(&mut self) -> Vec<String> {
        self.document.preprocess();
        self.document.tokenize();
        let mutator = TokenMutator::new(self.document.tokens.clone());
        mutator.mutate();
        mutator.mutated_tokens
    }
}

fn main() {
    let text_data = "This is a sample document. It contains several sentences.";
    let document = DocumentParser::new(text_data);
    let mut processor = DataProcessor::new(document);
    let result = processor.process();
    println!("{:?}", result);
}