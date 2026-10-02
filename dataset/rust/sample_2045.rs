use std::collections::HashMap;

struct Vectorizer {
    token_index: HashMap<String, usize>,
    vector_length: usize,
}

impl Vectorizer {
    fn new() -> Self {
        Vectorizer {
            token_index: HashMap::new(),
            vector_length: 0,
        }
    }

    fn fit(&mut self, documents: Vec<&str>) {
        for doc in documents {
            let tokens: Vec<&str> = doc.split_whitespace().collect();
            for token in tokens {
                if !self.token_index.contains_key(token) {
                    self.token_index.insert(token.to_string(), self.vector_length);
                    self.vector_length += 1;
                }
            }
        }
    }

    fn transform(&self, document: &str) -> Vec<usize> {
        let mut vector = vec![0; self.vector_length];
        for token in document.split_whitespace() {
            if let Some(&index) = self.token_index.get(token) {
                vector[index] += 1;
            }
        }
        vector
    }
}

struct DatasetProcessor {
    vectorizer: Vectorizer,
}

impl DatasetProcessor {
    fn new(vectorizer: Vectorizer) -> Self {
        DatasetProcessor { vectorizer }
    }

    fn process(&mut self, dataset: Vec<&str>) -> Vec<Vec<usize>> {
        self.vectorizer.fit(dataset.clone());
        dataset.iter().map(|&doc| self.vectorizer.transform(doc)).collect()
    }
}

struct AnalysisEngine {
    processor: DatasetProcessor,
}

impl AnalysisEngine {
    fn new(processor: DatasetProcessor) -> Self {
        AnalysisEngine { processor }
    }

    fn analyze(&self, dataset: Vec<&str>) -> Vec<Vec<usize>> {
        self.processor.process(dataset)
    }
}

fn main() {
    let documents = vec![
        "Natural language processing is fascinating",
        "Vectorization is key to NLP",
        "Machine learning and NLP go hand in hand",
    ];
    let vectorizer = Vectorizer::new();
    let processor = DatasetProcessor::new(vectorizer);
    let engine = AnalysisEngine::new(processor);
    let result = engine.analyze(documents);
    for vec in result {
        println!("{:?}", vec);
    }
}