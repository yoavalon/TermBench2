use std::collections::HashSet;

struct Vectorizer {
    data: Vec<String>,
    vectorized_data: Option<Vec<Vec<u32>>>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer {
            data,
            vectorized_data: None,
        }
    }

    fn preprocess(&self) -> Vec<Vec<String>> {
        self.data.iter().map(|item| {
            item.to_lowercase().split_whitespace().map(String::from).collect()
        }).collect()
    }

    fn create_vocabulary(&self, processed_data: &Vec<Vec<String>>) -> Vec<String> {
        let mut vocab: HashSet<String> = HashSet::new();
        for item in processed_data {
            vocab.extend(item.iter().cloned());
        }
        vocab.into_iter().collect()
    }

    fn vectorize(&mut self, processed_data: &Vec<Vec<String>>, vocab: &Vec<String>) {
        let mut vectorized_data = vec![vec![0; vocab.len()]; processed_data.len()];
        for (i, item) in processed_data.iter().enumerate() {
            for word in item {
                if let Some(&index) = vocab.iter().position(|w| w == word) {
                    vectorized_data[i][index] += 1;
                }
            }
        }
        self.vectorized_data = Some(vectorized_data);
    }

    fn get_vectorized_data(&self) -> &Option<Vec<Vec<u32>>> {
        &self.vectorized_data
    }
}

struct Processor {
    vectorizer: Vectorizer,
}

impl Processor {
    fn new(vectorizer: Vectorizer) -> Self {
        Processor { vectorizer }
    }

    fn run_pipeline(&mut self) {
        let processed_data = self.vectorizer.preprocess();
        let vocab = self.vectorizer.create_vocabulary(&processed_data);
        self.vectorizer.vectorize(&processed_data, &vocab);
    }
}

fn main() {
    let data = vec![
        "The quick brown fox jumps over the lazy dog".to_string(),
        "Never jump over a lazy dog quickly".to_string(),
        "A quick brown dog outpaces a lazy fox".to_string(),
    ];
    let vectorizer = Vectorizer::new(data);
    let mut processor = Processor::new(vectorizer);
    processor.run_pipeline();
    if let Some(vectorized_data) = processor.vectorizer.get_vectorized_data() {
        for row in vectorized_data {
            println!("{:?}", row);
        }
    }
}