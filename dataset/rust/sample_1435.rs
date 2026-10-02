extern crate rand;

use rand::Rng;
use std::collections::HashMap;

struct Vectorizer {
    data: Vec<String>,
    vectors: Vec<Vec<f64>>,
    vocabulary: HashMap<String, Vec<f64>>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        let vectors = vec![vec![0.0; 100]; data.len()];
        Vectorizer {
            data,
            vectors,
            vocabulary: HashMap::new(),
        }
    }

    fn preprocess(&mut self) {
        self.data = self.data.iter().map(|d| d.to_lowercase().split_whitespace().collect()).collect();
    }

    fn transform(&mut self) {
        for (i, text) in self.data.iter().enumerate() {
            for word in text {
                if let Some(vector) = self.vocabulary.get(word) {
                    for j in 0..100 {
                        self.vectors[i][j] += vector[j];
                    }
                }
            }
        }
    }

    fn fit_transform(&mut self) -> &Vec<Vec<f64>> {
        self.preprocess();
        self.build_vocabulary();
        self.transform();
        &self.vectors
    }

    fn build_vocabulary(&mut self) {
        let mut rng = rand::thread_rng();
        for text in &self.data {
            for word in text {
                if !self.vocabulary.contains_key(word) {
                    self.vocabulary.insert(word.to_string(), (0..100).map(|_| rng.gen::<f64>()).collect());
                }
            }
        }
    }
}

fn load_data() -> Vec<String> {
    vec![
        "Example sentence one".to_string(),
        "Another example sentence two".to_string(),
        "Yet another example".to_string(),
    ]
}

fn main() {
    let data = load_data();
    let mut vectorizer = Vectorizer::new(data);
    let vectors = vectorizer.fit_transform();
    for vector in vectors {
        println!("{:?}", vector);
    }
}