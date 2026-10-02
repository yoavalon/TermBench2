use std::collections::HashMap;
use std::sync::Mutex;
use std::thread;
use std::time::Duration;

struct TfidfVectorizer {
    idf: HashMap<String, f64>,
}

impl TfidfVectorizer {
    fn new() -> Self {
        TfidfVectorizer {
            idf: HashMap::new(),
        }
    }

    fn fit_transform(&mut self, data: Vec<&str>) -> Vec<Vec<f64>> {
        let mut term_freq = HashMap::new();
        let mut doc_count = 0.0;
        let mut terms = Vec::new();

        for text in data {
            doc_count += 1.0;
            let words: Vec<&str> = text.split_whitespace().collect();
            let mut unique_terms = HashMap::new();

            for word in words {
                *unique_terms.entry(word.to_string()).or_insert(0.0) += 1.0;
            }

            for (term, freq) in &unique_terms {
                *term_freq.entry(term.clone()).or_insert(0.0) += 1.0;
                terms.push(term.clone());
            }
        }

        for (term, df) in &term_freq {
            self.idf.insert(term.clone(), (doc_count / *df) as f64);
        }

        let mut X = Vec::new();

        for text in data {
            let words: Vec<&str> = text.split_whitespace().collect();
            let mut term_freqs = HashMap::new();

            for word in words {
                *term_freqs.entry(word.to_string()).or_insert(0.0) += 1.0;
            }

            let mut row = Vec::new();

            for term in &terms {
                let tf = term_freqs.get(term).unwrap_or(&0.0);
                let idf = self.idf.get(term).unwrap_or(&0.0);
                row.push(*tf * idf);
            }

            X.push(row);
        }

        X
    }
}

fn preprocess_data(data: Vec<&str>) -> Vec<Vec<f64>> {
    let mut vectorizer = TfidfVectorizer::new();
    vectorizer.fit_transform(data)
}

fn continuous_processing(X: Vec<Vec<f64>>) {
    loop {
        let transformed_data = X.clone();
        let mut processed_data = Vec::new();

        for row in transformed_data {
            let mut log_row = Vec::new();

            for &value in &row {
                log_row.push(value.ln() + 1.0);
            }

            processed_data.push(log_row);
        }

        for row in processed_data {
            println!("{:?}", row);
        }

        thread::sleep(Duration::from_secs(1));
    }
}

fn main() {
    let data_samples = vec!["Sample text data", "Another example", "NLP vectorization"];
    let X = preprocess_data(data_samples);
    continuous_processing(X);
}