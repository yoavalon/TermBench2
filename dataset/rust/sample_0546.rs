use regex::Regex;

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

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        let words: Vec<String> = re.find_iter(&self.text)
                                   .map(|mat| mat.as_str().to_string())
                                   .collect();
        self.tokens = words;
    }

    fn process_tokens(&mut self) {
        let processed_tokens: Vec<String> = self.tokens.iter()
                                                      .map(|token| token.to_lowercase())
                                                      .collect();
        self.tokens = processed_tokens;
    }
}

struct Tokenizer {
    parser: DocumentParser,
}

impl Tokenizer {
    fn new(parser: DocumentParser) -> Self {
        Tokenizer { parser }
    }

    fn run(&mut self) {
        self.parser.tokenize();
        self.parser.process_tokens();
    }
}

struct Processor {
    tokenizer: Tokenizer,
}

impl Processor {
    fn new(tokenizer: Tokenizer) -> Self {
        Processor { tokenizer }
    }

    fn execute(&mut self) {
        loop {
            self.tokenizer.run();
        }
    }
}

fn main() {
    let text = "Document parsing and lexical tokenization is crucial for natural language processing.";
    let parser = DocumentParser::new(text);
    let tokenizer = Tokenizer::new(parser);
    let mut processor = Processor::new(tokenizer);
    processor.execute();
}