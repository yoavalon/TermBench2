use std::collections::HashMap;
use std::iter::FromIterator;

struct TfidfVectorizer {
    max_features: usize,
    feature_index: HashMap<String, usize>,
}

impl TfidfVectorizer {
    fn new(max_features: usize) -> Self {
        TfidfVectorizer {
            max_features,
            feature_index: HashMap::new(),
        }
    }

    fn fit_transform(&mut self, data: Vec<&str>) -> Vec<Vec<f64>> {
        let mut feature_counts = HashMap::new();
        let mut total_docs = 0.0;

        for doc in data.iter() {
            let words: Vec<&str> = doc.split_whitespace().collect();
            let mut doc_feature_counts = HashMap::new();

            for &word in &words {
                *doc_feature_counts.entry(word).or_insert(0) += 1;
            }

            for (&word, &count) in &doc_feature_counts {
                *feature_counts.entry(word).or_insert(0) += 1;
            }

            total_docs += 1.0;
        }

        let mut feature_list: Vec<&str> = feature_counts.keys().cloned().collect();
        feature_list.sort_by_key(|&word| feature_counts[word]);
        feature_list.truncate(self.max_features);

        for (i, &word) in feature_list.iter().enumerate() {
            self.feature_index.insert(word.to_string(), i);
        }

        data.iter()
            .map(|doc| {
                let words: Vec<&str> = doc.split_whitespace().collect();
                let mut doc_vector = vec![0.0; self.max_features];
                let mut word_count = 0.0;

                for &word in &words {
                    if let Some(&index) = self.feature_index.get(word) {
                        doc_vector[index] += 1.0;
                        word_count += 1.0;
                    }
                }

                for value in &mut doc_vector {
                    *value = *value * (total_docs / (feature_counts[&feature_list[*value as usize]] as f64)) * (1.0 + (1.0 / word_count));
                    *value = value.log1p();
                }

                doc_vector
            })
            .collect()
    }
}

fn process_text(data: Vec<&str>, dim: usize) -> Vec<Vec<f64>> {
    let mut vectorizer = TfidfVectorizer::new(dim);
    vectorizer.fit_transform(data)
}

fn main() {
    let data = vec!["hello world", "goodbye universe", "python programming"];
    let result = process_text(data, 100);
    println!("{:?}", result);
}