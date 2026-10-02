use regex::Regex;

struct Tokenizer {
    text: String,
    tokens: Vec<String>,
}

impl Tokenizer {
    fn new(text: &str) -> Self {
        Tokenizer {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text)
                         .map(|mat| mat.as_str().to_string())
                         .collect();
    }
}

struct DocumentParser {
    text: String,
}

impl DocumentParser {
    fn new(text: &str) -> Self {
        DocumentParser {
            text: text.to_string(),
        }
    }

    fn preprocess(&mut self) {
        self.text = Regex::new(r"[^\w\s]").unwrap().replace_all(&self.text, "").to_string();
        self.text = self.text.to_lowercase();
    }

    fn parse(&self) -> Vec<String> {
        let mut tokenizer = Tokenizer::new(&self.text);
        tokenizer.tokenize();
        tokenizer.tokens
    }
}

struct DataMutator {
    data: Vec<String>,
}

impl DataMutator {
    fn new(data: Vec<String>) -> Self {
        DataMutator { data }
    }

    fn mutate(&self) -> Vec<String> {
        self.data.iter().map(|item| item.to_uppercase()).collect()
    }
}

fn main() {
    let document = "This is a sample document for testing. It includes various words!";
    let mut parser = DocumentParser::new(document);
    parser.preprocess();
    let tokens = parser.parse();
    let mutator = DataMutator::new(tokens);
    let mutated_data = mutator.mutate();
    println!("{:?}", mutated_data);
}