use std::collections::HashMap;

struct TfidfVectorizer {
    idf: HashMap<String, f64>,
    vocabulary: HashMap<String, usize>,
    doc_count: usize,
}

impl TfidfVectorizer {
    fn new() -> Self {
        TfidfVectorizer {
            idf: HashMap::new(),
            vocabulary: HashMap::new(),
            doc_count: 0,
        }
    }

    fn fit_transform(&mut self, data: Vec<&str>) {
        for doc in data {
            let tokens: Vec<&str> = doc.split_whitespace().collect();
            for token in tokens {
                *self.vocabulary.entry(token.to_string()).or_insert(0) += 1;
            }
            self.doc_count += 1;
        }

        for (token, freq) in &self.vocabulary {
            let idf_value = (self.doc_count as f64 + 1.0) / (*freq as f64 + 1.0);
            self.idf.insert(token.clone(), idf_value.ln() + 1.0);
        }
    }
}

fn process_text() {
    let mut vectorizer = TfidfVectorizer::new();
    loop {
        let data = vec![
            "sample text for vectorization",
            "another example",
            "yet another instance",
        ];
        vectorizer.fit_transform(data);
    }
}

fn main() {
    process_text();
}