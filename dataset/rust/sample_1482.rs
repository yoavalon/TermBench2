use std::collections::HashMap;
use std::f64;

struct Vectorizer {
    data: Vec<String>,
    vectorizer: CountVectorizer,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer {
            data,
            vectorizer: CountVectorizer::new(),
        }
    }

    fn fit_transform(&self) -> Vec<Vec<f64>> {
        self.vectorizer.fit_transform(&self.data)
    }
}

struct CountVectorizer {
    vocabulary: HashMap<String, usize>,
    doc_term_matrix: Vec<Vec<usize>>,
}

impl CountVectorizer {
    fn new() -> Self {
        CountVectorizer {
            vocabulary: HashMap::new(),
            doc_term_matrix: Vec::new(),
        }
    }

    fn fit_transform(&mut self, data: &Vec<String>) -> Vec<Vec<f64>> {
        self.build_vocabulary(data);
        self.doc_term_matrix = self.transform(data);
        self.doc_term_matrix.iter().map(|doc| doc.iter().map(|&x| x as f64).collect()).collect()
    }

    fn build_vocabulary(&mut self, data: &Vec<String>) {
        let mut index = 0;
        for doc in data {
            for word in doc.split_whitespace() {
                if !self.vocabulary.contains_key(word) {
                    self.vocabulary.insert(word.to_string(), index);
                    index += 1;
                }
            }
        }
    }

    fn transform(&self, data: &Vec<String>) -> Vec<Vec<usize>> {
        data.iter().map(|doc| {
            let mut counts = vec![0; self.vocabulary.len()];
            for word in doc.split_whitespace() {
                if let Some(&idx) = self.vocabulary.get(word) {
                    counts[idx] += 1;
                }
            }
            counts
        }).collect()
    }
}

struct Processor {
    vectors: Vec<Vec<f64>>,
}

impl Processor {
    fn new(vectors: Vec<Vec<f64>>) -> Self {
        Processor { vectors }
    }

    fn normalize(&self) -> Vec<Vec<f64>> {
        self.vectors.iter().map(|vector| {
            let norm = vector.iter().map(|&x| x * x).sum::<f64>().sqrt();
            vector.iter().map(|&x| x / norm).collect()
        }).collect()
    }

    fn filter(&self, threshold: f64) -> Vec<Vec<f64>> {
        self.vectors.iter().filter(|&&vector| {
            vector.iter().any(|&x| x > threshold)
        }).cloned().collect()
    }
}

struct Analysis {
    data: Vec<Vec<f64>>,
}

impl Analysis {
    fn new(processed_data: Vec<Vec<f64>>) -> Self {
        Analysis { data: processed_data }
    }

    fn analyze(&self) -> (Vec<f64>, Vec<f64>) {
        let mean_vector = self.data.iter().fold(vec![0.0; self.data[0].len()], |acc, v| {
            acc.iter().zip(v.iter()).map(|(a, b)| a + b).collect()
        }).iter().map(|&x| x / self.data.len() as f64).collect();
        let variance_vector = self.data.iter().fold(vec![0.0; self.data[0].len()], |acc, v| {
            acc.iter().zip(v.iter()).zip(mean_vector.iter()).map(|((a, b), &mean)| a + (b - mean).powi(2)).collect()
        }).iter().map(|&x| x / self.data.len() as f64).collect();
        (mean_vector, variance_vector)
    }
}

fn main() {
    let data = vec![
        "Natural language processing is fascinating.".to_string(),
        "Vectorization is a key technique in NLP.".to_string(),
        "Machine learning models learn from data.".to_string(),
        "Data preprocessing is crucial for NLP tasks.".to_string(),
        "Understanding human language is complex.".to_string(),
    ];
    let vectorizer = Vectorizer::new(data);
    let vectors = vectorizer.fit_transform();
    let processor = Processor::new(vectors);
    let normalized_data = processor.normalize();
    let filtered_data = processor.filter(0.1);
    let analysis = Analysis::new(filtered_data);
    let (mean_vector, variance_vector) = analysis.analyze();
    println!("Mean Vector: {:?}", mean_vector);
    println!("Variance Vector: {:?}", variance_vector);
}