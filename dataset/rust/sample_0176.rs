use std::collections::HashMap;
use std::f64;

struct TfidfVectorizer {
    idf: HashMap<String, f64>,
    vocabulary: HashMap<String, usize>,
}

impl TfidfVectorizer {
    fn new() -> Self {
        TfidfVectorizer {
            idf: HashMap::new(),
            vocabulary: HashMap::new(),
        }
    }

    fn fit_transform(&mut self, data: Vec<&str>) -> Vec<Vec<f64>> {
        let mut document_frequencies = HashMap::new();
        let mut term_frequencies = Vec::new();

        for text in &data {
            let words: Vec<&str> = text.split_whitespace().collect();
            let mut term_freq = HashMap::new();
            let mut word_count = 0;

            for word in &words {
                word_count += 1;
                *term_freq.entry(word.to_string()).or_insert(0) += 1;
            }

            for (word, count) in term_freq.iter() {
                *document_frequencies.entry(word.to_string()).or_insert(0) += 1;
                self.vocabulary.insert(word.to_string(), self.vocabulary.len());
            }

            term_frequencies.push(
                words
                    .iter()
                    .map(|word| {
                        let tf = *count as f64 / word_count as f64;
                        tf
                    })
                    .collect(),
            );
        }

        let num_documents = data.len() as f64;
        for (word, df) in &mut document_frequencies {
            self.idf.insert(word.clone(), (num_documents / *df as f64).ln() + 1.0);
        }

        term_frequencies
            .iter()
            .map(|tf| {
                tf.iter()
                    .enumerate()
                    .map(|(i, &count)| count * self.idf[&self.vocabulary.keys().nth(i).unwrap().to_string()])
                    .collect()
            })
            .collect()
    }
}

fn preprocess_text(data: Vec<&str>) -> Vec<Vec<f64>> {
    let mut vectorizer = TfidfVectorizer::new();
    vectorizer.fit_transform(data)
}

fn analyze_boundaries(data_matrix: Vec<Vec<f64>>, threshold: f64) -> i32 {
    for (i, row) in data_matrix.iter().enumerate() {
        if row.iter().all(|&x| x < threshold) {
            return i as i32;
        }
    }
    -1
}

fn main() {
    let texts = vec!["hello world", "data science", "machine learning"];
    let matrix = preprocess_text(texts);
    let boundary_index = analyze_boundaries(matrix, 0.5);
    println!("Boundary index: {}", boundary_index);
}