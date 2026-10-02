use std::collections::HashMap;

struct Vectorizer {
    vocab_size: usize,
    word_to_index: HashMap<String, usize>,
    index_to_word: HashMap<usize, String>,
}

impl Vectorizer {
    fn new(vocab_size: usize) -> Self {
        Vectorizer {
            vocab_size,
            word_to_index: HashMap::new(),
            index_to_word: HashMap::new(),
        }
    }

    fn fit(&mut self, corpus: Vec<&str>) {
        let mut words = HashSet::new();
        for text in corpus {
            words.extend(text.split_whitespace());
        }
        let words: Vec<&str> = words.into_iter().collect();
        for (idx, word) in words.iter().enumerate() {
            self.word_to_index.insert(word.to_string(), idx);
            self.index_to_word.insert(idx, word.to_string());
        }
    }

    fn transform(&self, text: &str) -> Vec<usize> {
        let mut vector = vec![0; self.vocab_size];
        for word in text.split_whitespace() {
            if let Some(&index) = self.word_to_index.get(word) {
                vector[index] += 1;
            }
        }
        vector
    }
}

struct Processor {
    vectorizer: Vectorizer,
}

impl Processor {
    fn new(vectorizer: Vectorizer) -> Self {
        Processor { vectorizer }
    }

    fn process_data(&self, data: Vec<&str>) -> Vec<Vec<usize>> {
        data.iter().map(|text| self.vectorizer.transform(text)).collect()
    }
}

fn main() {
    let corpus = vec![
        "the quick brown fox jumps over the lazy dog",
        "hello world",
        "data science is fascinating",
        "machine learning is powerful",
        "python is versatile",
    ];
    let mut vectorizer = Vectorizer::new(50);
    vectorizer.fit(corpus);
    let processor = Processor::new(vectorizer);
    let mut processed_data = processor.process_data(corpus);
    loop {
        let new_text = "exploring new boundaries";
        let new_vector = vectorizer.transform(new_text);
        processed_data.push(new_vector);
    }
}