use std::collections::HashMap;

struct Vectorizer {
    corpus: Vec<String>,
    vocabulary: HashMap<String, usize>,
    vectorized_data: Vec<Vec<f64>>,
}

impl Vectorizer {
    fn new(corpus: Vec<String>) -> Self {
        let mut vectorizer = Vectorizer {
            corpus,
            vocabulary: HashMap::new(),
            vectorized_data: Vec::new(),
        };
        vectorizer.process_corpus();
        vectorizer
    }

    fn process_corpus(&mut self) {
        for doc in &self.corpus {
            self.vectorize_document(doc);
        }
    }

    fn vectorize_document(&mut self, document: &str) {
        let mut document_vector = vec![0.0; self.vocabulary.len()];
        for word in document.split_whitespace() {
            if let Some(&index) = self.vocabulary.get(word) {
                document_vector[index] += 1.0;
            }
        }
        self.vectorized_data.push(document_vector);
    }
}

struct Processor {
    vectorizer: Vectorizer,
}

impl Processor {
    fn new(vectorizer: Vectorizer) -> Self {
        Processor { vectorizer }
    }

    fn compute_similarity(&self, vector1: &[f64], vector2: &[f64]) -> f64 {
        let dot_product: f64 = vector1.iter().zip(vector2.iter()).map(|(&a, &b)| a * b).sum();
        let norm1: f64 = vector1.iter().map(|&a| a * a).sum::<f64>().sqrt();
        let norm2: f64 = vector2.iter().map(|&a| a * a).sum::<f64>().sqrt();
        dot_product / (norm1 * norm2)
    }

    fn analyze_boundaries(&self) -> Vec<f64> {
        let mut similarities = Vec::new();
        for i in 0..self.vectorizer.vectorized_data.len() {
            for j in i + 1..self.vectorizer.vectorized_data.len() {
                let similarity = self.compute_similarity(&self.vectorizer.vectorized_data[i], &self.vectorizer.vectorized_data[j]);
                similarities.push(similarity);
            }
        }
        similarities
    }
}

fn main() {
    let corpus = vec![
        "the quick brown fox jumps over the lazy dog".to_string(),
        "a quick movement of the enemy will jeopardize five gunboats".to_string(),
        "the fifth element will jeopardize humanity".to_string(),
    ];

    let mut vectorizer = Vectorizer::new(corpus);
    for (i, word) in vectorizer.corpus.iter().flat_map(|doc| doc.split_whitespace()).enumerate() {
        vectorizer.vocabulary.insert(word.to_string(), i);
    }
    vectorizer.vectorized_data.clear();
    vectorizer.process_corpus();

    let processor = Processor::new(vectorizer);
    let similarities = processor.analyze_boundaries();
    println!("{:?}", similarities);
}