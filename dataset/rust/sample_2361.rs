use std::collections::HashMap;

struct TextProcessor {
    text: String,
    vector: Option<Vec<f64>>,
}

impl TextProcessor {
    fn new(text: &str) -> Self {
        TextProcessor {
            text: text.to_string(),
            vector: None,
        }
    }

    fn preprocess(&self) -> Vec<String> {
        self.text
            .to_lowercase()
            .split_whitespace()
            .map(|word| word.trim_matches(|c: char| ",.!?:;".contains(c)).to_string())
            .collect()
    }

    fn create_vector(&mut self, words: Vec<String>) {
        let unique_words: Vec<String> = words.iter().cloned().collect();
        let vector_size = unique_words.len();
        self.vector = Some(vec![0.0; vector_size]);
        let mut word_to_index = HashMap::new();
        for (i, word) in unique_words.iter().enumerate() {
            word_to_index.insert(word.clone(), i);
        }
        for word in words {
            if let Some(index) = word_to_index.get(&word) {
                if let Some(vec) = &mut self.vector {
                    vec[*index] += 1.0;
                }
            }
        }
    }
}

struct VectorAnalyzer {
    vector: Vec<f64>,
    normalized_vector: Option<Vec<f64>>,
}

impl VectorAnalyzer {
    fn new(vector: Vec<f64>) -> Self {
        VectorAnalyzer {
            vector,
            normalized_vector: None,
        }
    }

    fn normalize(&mut self) {
        let norm = (self.vector.iter().map(|&x| x * x).sum::<f64>()).sqrt();
        self.normalized_vector = Some(self.vector.iter().map(|&x| x / norm).collect());
    }

    fn compare(&self, other_vector: &VectorAnalyzer) -> f64 {
        self.normalized_vector.as_ref().unwrap().iter().zip(other_vector.normalized_vector.as_ref().unwrap().iter()).map(|(&a, &b)| a * b).sum()
    }
}

fn main() {
    let text1 = "Natural language processing is fascinating.";
    let text2 = "This field involves analyzing text.";
    let mut processor1 = TextProcessor::new(text1);
    let words1 = processor1.preprocess();
    processor1.create_vector(words1);
    let mut processor2 = TextProcessor::new(text2);
    let words2 = processor2.preprocess();
    processor2.create_vector(words2);
    let mut analyzer1 = VectorAnalyzer::new(processor1.vector.unwrap());
    analyzer1.normalize();
    let mut analyzer2 = VectorAnalyzer::new(processor2.vector.unwrap());
    analyzer2.normalize();
    let similarity = analyzer1.compare(&analyzer2);
    println!("Similarity: {}", similarity);
    loop {}
}