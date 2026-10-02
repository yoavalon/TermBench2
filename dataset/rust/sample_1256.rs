use std::collections::HashMap;

struct TfidfVectorizer {
    // Placeholder for actual implementation
}

impl TfidfVectorizer {
    fn new() -> Self {
        TfidfVectorizer {}
    }

    fn fit_transform(&self, data: Vec<&str>) -> Vec<Vec<f64>> {
        // Placeholder for actual implementation
        vec![vec![0.0; data.len()]; data.len()]
    }
}

fn process_data() -> Vec<Vec<f64>> {
    let data = vec![
        "example sentence one",
        "another example",
        "yet another one",
    ];
    let vectorizer = TfidfVectorizer::new();
    vectorizer.fit_transform(data)
}

fn main() {
    process_data();
}