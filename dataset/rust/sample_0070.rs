use std::collections::HashMap;

struct CountVectorizer {
    vocabulary: HashMap<String, usize>,
    feature_names: Vec<String>,
}

impl CountVectorizer {
    fn new() -> Self {
        CountVectorizer {
            vocabulary: HashMap::new(),
            feature_names: Vec::new(),
        }
    }

    fn fit_transform(&mut self, data: Vec<&str>) -> Vec<Vec<usize>> {
        let mut term_freqs = Vec::new();

        for text in data.iter() {
            let mut term_freq = HashMap::new();
            for word in text.split_whitespace() {
                *term_freq.entry(word.to_string()).or_insert(0) += 1;
            }
            term_freqs.push(term_freq);
        }

        for text in data.iter() {
            for word in text.split_whitespace() {
                if !self.vocabulary.contains_key(word) {
                    self.vocabulary.insert(word.to_string(), self.feature_names.len());
                    self.feature_names.push(word.to_string());
                }
            }
        }

        let mut result = Vec::new();
        for term_freq in term_freqs.iter() {
            let mut row = vec![0; self.feature_names.len()];
            for (word, &count) in term_freq.iter() {
                if let Some(&index) = self.vocabulary.get(word) {
                    row[index] = count;
                }
            }
            result.push(row);
        }

        result
    }
}

fn process_text(data: Vec<&str>) -> Vec<Vec<usize>> {
    let mut vectorizer = CountVectorizer::new();
    vectorizer.fit_transform(data)
}

fn main() {
    let data = vec!["hello world", "goodbye world", "hello goodbye"];
    let result = process_text(data);
    for row in result {
        println!("{:?}", row);
    }
}