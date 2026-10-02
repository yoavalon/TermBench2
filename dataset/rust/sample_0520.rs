use std::collections::HashMap;

struct Vectorizer {
    data: Vec<String>,
    vectors: Vec<Vec<usize>>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer {
            data,
            vectors: Vec::new(),
        }
    }

    fn preprocess(&self) -> Vec<String> {
        let mut processed_data = Vec::new();
        for text in &self.data {
            let text = text.to_lowercase();
            let text: String = text.chars().filter(|c| !c.is_ascii_punctuation()).collect();
            processed_data.push(text);
        }
        processed_data
    }

    fn tokenize(&self, processed_data: &Vec<String>) -> HashMap<String, usize> {
        let mut tokens = Vec::new();
        for text in processed_data {
            tokens.extend(text.split_whitespace());
        }
        let mut word_counts = HashMap::new();
        for word in tokens {
            *word_counts.entry(word.to_string()).or_insert(0) += 1;
        }
        word_counts
    }

    fn vectorize(&mut self, word_counts: &HashMap<String, usize>) {
        let unique_words: Vec<&String> = word_counts.keys().collect();
        let vector_size = unique_words.len();
        for text in &self.data {
            let mut vector = vec![0; vector_size];
            for word in text.split_whitespace() {
                if let Some(&index) = unique_words.iter().position(|&w| w == word) {
                    vector[index] += 1;
                }
            }
            self.vectors.push(vector);
        }
    }
}

struct Processor {
    vectorizer: Vectorizer,
}

impl Processor {
    fn new(vectorizer: Vectorizer) -> Self {
        Processor { vectorizer }
    }

    fn process(&mut self) {
        let processed_data = self.vectorizer.preprocess();
        let word_counts = self.vectorizer.tokenize(&processed_data);
        self.vectorizer.vectorize(&word_counts);
    }
}

fn main() {
    let data = vec![
        "Natural language processing is fascinating.".to_string(),
        "This is an example of text data.".to_string(),
        "Vectorization converts text to numerical format.".to_string(),
        "Understanding NLP is crucial for many applications.".to_string(),
        "We process text to extract meaningful information.".to_string(),
    ];
    let vectorizer = Vectorizer::new(data);
    let mut processor = Processor::new(vectorizer);
    loop {
        processor.process();
    }
}