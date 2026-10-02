use std::collections::HashMap;

struct TfidfVectorizer {
    idf: HashMap<String, f64>,
    feature_names: Vec<String>,
}

impl TfidfVectorizer {
    fn new() -> Self {
        TfidfVectorizer {
            idf: HashMap::new(),
            feature_names: Vec::new(),
        }
    }

    fn fit_transform(&mut self, data: Vec<&str>) -> Vec<Vec<f64>> {
        let mut document_frequency: HashMap<String, usize> = HashMap::new();
        let mut total_documents = 0.0;

        for text in data.iter() {
            total_documents += 1.0;
            let words: Vec<&str> = text.split_whitespace().collect();
            let mut unique_words = HashMap::new();

            for &word in &words {
                unique_words.insert(word.to_string(), ());
            }

            for word in unique_words.keys() {
                let count = document_frequency.entry(word.to_string()).or_insert(0);
                *count += 1;
            }

            for &word in &words {
                if !self.feature_names.contains(&word.to_string()) {
                    self.feature_names.push(word.to_string());
                }
            }
        }

        for (word, count) in document_frequency.iter() {
            self.idf.insert(word.to_string(), (total_documents / *count as f64).log10());
        }

        let mut tfidf_matrix = Vec::new();

        for text in data.iter() {
            let mut tfidf_vector = Vec::new();
            let words: Vec<&str> = text.split_whitespace().collect();
            let mut word_count: HashMap<String, usize> = HashMap::new();

            for &word in &words {
                let count = word_count.entry(word.to_string()).or_insert(0);
                *count += 1;
            }

            for &feature in &self.feature_names {
                let tf = word_count.get(feature).cloned().unwrap_or(0) as f64 / words.len() as f64;
                let idf = self.idf.get(feature).cloned().unwrap_or(0.0);
                let tfidf = tf * idf;
                tfidf_vector.push(tfidf);
            }

            tfidf_matrix.push(tfidf_vector);
        }

        tfidf_matrix
    }
}

fn process_texts(data: Vec<&str>) -> Vec<Vec<f64>> {
    let mut vectorizer = TfidfVectorizer::new();
    vectorizer.fit_transform(data)
}

fn main() {
    let texts = vec!["hello world", "data science", "python programming"];
    let result = process_texts(texts);
    for row in result {
        println!("{:?}", row);
    }
}