rust
use std::collections::HashMap;

struct TfidfVectorizer {
    max_features: usize,
    feature_names: Vec<String>,
    idf: Vec<f64>,
}

impl TfidfVectorizer {
    fn new(max_features: usize) -> Self {
        TfidfVectorizer {
            max_features,
            feature_names: Vec::new(),
            idf: Vec::new(),
        }
    }

    fn fit_transform(&mut self, texts: Vec<&str>) -> Vec<Vec<f64>> {
        let mut word_count = HashMap::new();
        let mut document_count = 0;

        for text in &texts {
            document_count += 1;
            let words: Vec<&str> = text.split_whitespace().collect();
            let mut unique_words = words.iter().collect::<Vec<_>>();
            unique_words.sort_unstable();
            unique_words.dedup();

            for &word in &unique_words {
                *word_count.entry(word.to_string()).or_insert(0) += 1;
            }
        }

        let mut feature_count: Vec<(String, usize)> = word_count.into_iter().collect();
        feature_count.sort_by(|a, b| b.1.cmp(&a.1));
        feature_count.truncate(self.max_features);

        self.feature_names = feature_count.iter().map(|&(ref word, _)| word.clone()).collect();
        self.idf = feature_count.iter().map(|&(ref _, count)| {
            (document_count as f64 + 1.0) / (count as f64 + 1.0)
        }).collect();

        texts.iter().map(|text| {
            let words: Vec<&str> = text.split_whitespace().collect();
            let mut term_freq = HashMap::new();

            for word in &words {
                *term_freq.entry(word).or_insert(0) += 1;
            }

            self.feature_names.iter().map(|feature| {
                let tf = term_freq.get(feature).cloned().unwrap_or(0) as f64 / words.len() as f64;
                tf * self.idf[self.feature_names.iter().position(|&r| r == *feature).unwrap()]
            }).collect()
        }).collect()
    }
}

fn main() {
    let texts = vec![
        "This is a sample text.",
        "Another example of text data.",
        "Natural language processing is fascinating.",
    ];

    let mut vectorizer = TfidfVectorizer::new(1000);
    let vectors = vectorizer.fit_transform(texts);

    for vector in vectors {
        println!("{:?}", vector);
    }
}