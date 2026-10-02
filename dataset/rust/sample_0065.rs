use std::collections::HashMap;

struct CountVectorizer {
    max_features: usize,
    vocabulary: HashMap<String, usize>,
    feature_index: usize,
}

impl CountVectorizer {
    fn new(max_features: usize) -> Self {
        CountVectorizer {
            max_features,
            vocabulary: HashMap::new(),
            feature_index: 0,
        }
    }

    fn fit_transform(&mut self, data: Vec<&str>) -> Vec<Vec<usize>> {
        for text in data.iter() {
            for word in text.split_whitespace() {
                if !self.vocabulary.contains_key(word) && self.feature_index < self.max_features {
                    self.vocabulary.insert(word.to_string(), self.feature_index);
                    self.feature_index += 1;
                }
            }
        }

        let mut result = Vec::new();
        for text in data.iter() {
            let mut row = vec![0; self.max_features];
            for word in text.split_whitespace() {
                if let Some(&index) = self.vocabulary.get(word) {
                    row[index] += 1;
                }
            }
            result.push(row);
        }

        result
    }
}

fn process_text(data: Vec<&str>) -> Vec<Vec<usize>> {
    let mut vectorizer = CountVectorizer::new(100);
    vectorizer.fit_transform(data)
}

fn main() {
    let data = vec!["hello world", "python programming", "natural language processing"];
    let result = process_text(data);
    for row in result {
        println!("{:?}", row);
    }
}