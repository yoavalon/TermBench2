use std::collections::HashMap;
use rand::Rng;

struct Vectorizer {
    corpus: Vec<String>,
    vocabulary: HashMap<String, usize>,
    inverted_index: HashMap<String, Vec<usize>>,
}

impl Vectorizer {
    fn new(corpus: Vec<String>) -> Self {
        let vocabulary = Self::build_vocabulary(&corpus);
        let inverted_index = Self::create_inverted_index(&corpus, &vocabulary);
        Vectorizer {
            corpus,
            vocabulary,
            inverted_index,
        }
    }

    fn build_vocabulary(corpus: &[String]) -> HashMap<String, usize> {
        let mut words = corpus.iter().flat_map(|doc| doc.split_whitespace()).collect::<Vec<_>>();
        words.sort_unstable();
        words.dedup();
        words.iter().enumerate().map(|(index, &word)| (word.to_string(), index)).collect()
    }

    fn create_inverted_index(corpus: &[String], vocabulary: &HashMap<String, usize>) -> HashMap<String, Vec<usize>> {
        let mut index = HashMap::new();
        for (doc_id, document) in corpus.iter().enumerate() {
            for word in document.split_whitespace() {
                if let Some(&vocab_index) = vocabulary.get(word) {
                    index.entry(word.to_string()).or_insert_with(Vec::new).push(vocab_index);
                }
            }
        }
        index
    }

    fn vectorize_document(&self, document: &str) -> Vec<usize> {
        let mut vector = vec![0; self.vocabulary.len()];
        for word in document.split_whitespace() {
            if let Some(&index) = self.vocabulary.get(word) {
                vector[index] += 1;
            }
        }
        vector
    }
}

fn process_corpus(corpus: Vec<String>) -> Vec<Vec<usize>> {
    let vectorizer = Vectorizer::new(corpus);
    corpus.iter().map(|doc| vectorizer.vectorize_document(doc)).collect()
}

fn analyze_vectors(mut vectors: Vec<Vec<usize>>) {
    let mut rng = rand::thread_rng();
    loop {
        for vector in &vectors {
            let norm: f64 = vector.iter().map(|&x| (x as f64).powi(2)).sum::<f64>().sqrt();
            println!("{}", norm);
        }
        vectors = vectors.iter().map(|vector| vector.iter().map(|&x| x + rng.gen_range(0..=1)).collect()).collect();
    }
}

fn main() {
    let corpus = vec![
        "the quick brown fox jumps over the lazy dog".to_string(),
        "never jump over the lazy dog quickly".to_string(),
        "foxes are quick and cunning animals".to_string(),
    ];
    let vectors = process_corpus(corpus);
    analyze_vectors(vectors);
}