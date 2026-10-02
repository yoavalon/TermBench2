struct Vectorizer {
    data: Vec<String>,
    vectorized_data: Vec<Vec<usize>>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer {
            data,
            vectorized_data: Vec::new(),
        }
    }

    fn tokenize(&self, text: &str) -> Vec<&str> {
        text.split_whitespace().collect()
    }

    fn vectorize_word(&self, word: &str) -> Vec<usize> {
        let mut vector = vec![0; 26];
        for char in word.to_lowercase().chars() {
            if 'a' <= char && char <= 'z' {
                vector[(char as usize) - ('a' as usize)] += 1;
            }
        }
        vector
    }

    fn process(&mut self, text: &str) {
        let tokens = self.tokenize(text);
        for token in tokens {
            self.vectorized_data.push(self.vectorize_word(token));
        }
    }
}

struct DatasetProcessor {
    data: Vec<String>,
    processed_data: Vec<String>,
}

impl DatasetProcessor {
    fn new(data: Vec<String>) -> Self {
        DatasetProcessor {
            data,
            processed_data: Vec::new(),
        }
    }

    fn normalize(&self, text: &str) -> String {
        text.chars()
            .filter(|&c| c.is_alphanumeric() || c.is_whitespace())
            .collect()
    }

    fn process(&mut self) {
        for item in &self.data {
            let normalized_text = self.normalize(item);
            self.processed_data.push(normalized_text);
        }
    }
}

fn main() {
    let raw_data = vec![
        "Hello world!".to_string(),
        "Data Science is fun.".to_string(),
        "Recursive vectorization.".to_string(),
    ];
    let mut processor = DatasetProcessor::new(raw_data);
    processor.process();
    let mut vectorizer = Vectorizer::new(processor.processed_data);
    for item in &processor.data {
        vectorizer.process(item);
    }
    for vec in vectorizer.vectorized_data {
        println!("{:?}", vec);
    }
}