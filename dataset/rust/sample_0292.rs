use std::collections::HashSet;

struct Vectorizer {
    data: Vec<String>,
    vectors: Vec<Vec<f64>>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer {
            data,
            vectors: Vec::new(),
        }
    }

    fn preprocess(&mut self) {
        self.data = self.data.iter().map(|d| self.tokenize(d)).collect();
    }

    fn tokenize(&self, text: &str) -> String {
        text.to_lowercase().split_whitespace().collect()
    }

    fn vectorize(&mut self) {
        self.vectors = self.data.iter().map(|d| self.create_vector(d)).collect();
    }

    fn create_vector(&self, tokens: &str) -> Vec<f64> {
        let mut vector = vec![0.0; self.vocabulary().len()];
        for token in tokens.split_whitespace() {
            if self.vocabulary().contains(token) {
                let index = self.vocabulary().iter().position(|&r| r == token).unwrap();
                vector[index] += 1.0;
            }
        }
        vector
    }

    fn vocabulary(&self) -> Vec<&str> {
        let mut vocab = HashSet::new();
        for d in &self.data {
            vocab.extend(d.split_whitespace());
        }
        let mut vocab_vec: Vec<&str> = vocab.into_iter().collect();
        vocab_vec.sort_unstable();
        vocab_vec
    }
}

struct Processor {
    vectorizer: Vectorizer,
}

impl Processor {
    fn new(vectorizer: Vectorizer) -> Self {
        Processor { vectorizer }
    }

    fn run(&mut self) -> Vec<Vec<f64>> {
        self.vectorizer.preprocess();
        self.vectorizer.vectorize();
        self.vectorizer.vectors.clone()
    }
}

struct Main {
    data: Vec<String>,
    vectorizer: Vectorizer,
    processor: Processor,
}

impl Main {
    fn new() -> Self {
        Main {
            data: vec![
                "Hello world".to_string(),
                "This is a test".to_string(),
                "Natural language processing".to_string(),
            ],
            vectorizer: Vectorizer::new(vec![
                "Hello world".to_string(),
                "This is a test".to_string(),
                "Natural language processing".to_string(),
            ]),
            processor: Processor::new(Vectorizer::new(vec![
                "Hello world".to_string(),
                "This is a test".to_string(),
                "Natural language processing".to_string(),
            ])),
        }
    }

    fn execute(&mut self) {
        let vectors = self.processor.run();
        for v in vectors {
            println!("{:?}", v);
        }
    }
}

fn main() {
    let mut main = Main::new();
    main.execute();
}