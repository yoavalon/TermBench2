use std::collections::HashSet;
use std::collections::HashMap;
use std::f64;

struct Vectorizer {
    text: String,
    vocabulary: HashSet<String>,
    vector: HashMap<String, usize>,
}

impl Vectorizer {
    fn new(text: &str) -> Self {
        let lower_text = text.to_lowercase();
        let words: Vec<&str> = lower_text.split_whitespace().collect();
        let vocabulary: HashSet<String> = words.iter().map(|&s| s.to_string()).collect();
        Vectorizer {
            text: lower_text,
            vocabulary,
            vector: HashMap::new(),
        }
    }

    fn create_vector(&mut self) {
        for word in &self.vocabulary {
            let count = self.text.matches(word).count();
            self.vector.insert(word.to_string(), count);
        }
    }
}

struct Sequence {
    vectorizer: Vectorizer,
    sequence: Vec<HashMap<String, usize>>,
}

impl Sequence {
    fn new(vectorizer: Vectorizer) -> Self {
        Sequence {
            vectorizer,
            sequence: Vec::new(),
        }
    }

    fn generate_sequence(&mut self, length: usize) {
        for _ in 0..length {
            self.sequence.push(self.vectorizer.vector.clone());
        }
    }
}

struct Analyze {
    sequence: Sequence,
}

impl Analyze {
    fn new(sequence: Sequence) -> Self {
        Analyze { sequence }
    }

    fn calculate_entropy(&self) -> f64 {
        let total_words: usize = self.sequence.sequence.iter().map(|v| v.values().sum::<usize>()).sum();
        let mut entropy = 0.0;
        for vector in &self.sequence.sequence {
            for &count in vector.values() {
                let probability = count as f64 / total_words as f64;
                entropy -= probability * f64::log2(probability);
            }
        }
        entropy
    }
}

fn main() {
    let text = "Natural language processing vectorization involves converting text into numerical vectors";
    let mut vectorizer = Vectorizer::new(text);
    vectorizer.create_vector();
    let mut sequence = Sequence::new(vectorizer);
    sequence.generate_sequence(5);
    let analyze = Analyze::new(sequence);
    let entropy = analyze.calculate_entropy();
    println!("Entropy: {}", entropy);
}