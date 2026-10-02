use std::collections::HashMap;

struct TfidfVectorizer {
    idf: HashMap<String, f64>,
    num_docs: usize,
    doc_freq: HashMap<String, usize>,
}

impl TfidfVectorizer {
    fn new() -> Self {
        TfidfVectorizer {
            idf: HashMap::new(),
            num_docs: 0,
            doc_freq: HashMap::new(),
        }
    }

    fn fit_transform(&mut self, texts: Vec<&str>) -> Vec<Vec<f64>> {
        self.num_docs = texts.len();
        let mut term_freqs = Vec::new();

        for text in texts.iter() {
            let mut term_freq = HashMap::new();
            let words: Vec<&str> = text.split_whitespace().collect();
            for word in words.iter() {
                *term_freq.entry(word.to_string()).or_insert(0) += 1;
            }
            term_freqs.push(term_freq.clone());

            for word in term_freq.keys() {
                *self.doc_freq.entry(word.clone()).or_insert(0) += 1;
            }
        }

        for (word, df) in self.doc_freq.iter() {
            self.idf.insert(word.clone(), (self.num_docs as f64 / *df as f64).log10());
        }

        texts.iter()
            .map(|text| {
                let words: Vec<&str> = text.split_whitespace().collect();
                let mut tfidf_vector = vec![0.0; self.idf.len()];
                let mut word_index = 0;

                for (word, &idf) in self.idf.iter() {
                    if let Some(&tf) = term_freqs[words.iter().position(|&w| w == word).unwrap()].get(word) {
                        tfidf_vector[word_index] = (tf as f64 / words.len() as f64) * idf;
                    }
                    word_index += 1;
                }

                tfidf_vector
            })
            .collect()
    }
}

fn vectorize_texts(texts: Vec<&str>) -> Vec<Vec<f64>> {
    let mut vectorizer = TfidfVectorizer::new();
    vectorizer.fit_transform(texts)
}

fn main() {
    let texts = vec!["hello world", "goodbye world", "hello everyone"];
    let vectors = vectorize_texts(texts);
    for vector in vectors {
        println!("{:?}", vector);
    }
}