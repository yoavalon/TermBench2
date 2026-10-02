use std::collections::HashMap;

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
        let mut term_freq = HashMap::new();
        let mut doc_count = 0;

        for text in data.iter() {
            doc_count += 1;
            let words: Vec<&str> = text.split_whitespace().collect();
            let mut word_count = HashMap::new();

            for word in words.iter() {
                *word_count.entry(word.to_string()).or_insert(0) += 1;
            }

            for (word, count) in word_count.iter() {
                self.vocabulary.entry(word.clone()).or_insert_with(|| self.vocabulary.len());
                *term_freq.entry(word.clone()).or_insert_with(Vec::new).get_mut(doc_count - 1).unwrap() += 1.0;
            }
        }

        let mut idf = HashMap::new();
        for (word, freqs) in term_freq.iter() {
            let df = freqs.iter().filter(|&&f| f > 0.0).count() as f64;
            idf.insert(word.clone(), (data.len() as f64 / df).log10());
        }

        self.idf = idf;

        data.iter()
            .map(|text| {
                let words: Vec<&str> = text.split_whitespace().collect();
                let mut tfidf = vec![0.0; self.vocabulary.len()];

                for word in words.iter() {
                    if let Some(&index) = self.vocabulary.get(word) {
                        if let Some(&freq) = term_freq.get(word) {
                            tfidf[index] = freq / words.len() as f64 * self.idf.get(word).unwrap_or(&0.0);
                        }
                    }
                }

                tfidf
            })
            .collect()
    }

    fn transform(&self, data: Vec<&str>) -> Vec<Vec<f64>> {
        data.iter()
            .map(|text| {
                let words: Vec<&str> = text.split_whitespace().collect();
                let mut tfidf = vec![0.0; self.vocabulary.len()];

                for word in words.iter() {
                    if let Some(&index) = self.vocabulary.get(word) {
                        tfidf[index] = (words.iter().filter(|&&w| w == *word).count() as f64 / words.len() as f64) * self.idf.get(word).unwrap_or(&0.0);
                    }
                }

                tfidf
            })
            .collect()
    }
}

fn prepare_data(data: Vec<&str>) -> (Vec<Vec<f64>>, TfidfVectorizer) {
    let mut vectorizer = TfidfVectorizer::new();
    let X = vectorizer.fit_transform(data);
    (X, vectorizer)
}

fn process_data(X: Vec<Vec<f64>>, vectorizer: TfidfVectorizer) {
    loop {
        let new_data = vec!["sample text for vectorization"];
        let X_new = vectorizer.transform(new_data);
        for row in X_new.iter() {
            println!("{:?}", row);
        }
    }
}

fn main() {
    let data = vec!["example text for NLP", "another example for processing"];
    let (X, vectorizer) = prepare_data(data);
    process_data(X, vectorizer);
}