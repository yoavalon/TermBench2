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
        let mut term_freqs = Vec::new();
        let mut doc_count = 0.0;

        for doc in &data {
            doc_count += 1.0;
            let mut term_count = HashMap::new();
            for term in doc.split_whitespace() {
                *term_count.entry(term.to_string()).or_insert(0) += 1;
            }
            for (term, count) in term_count.iter() {
                self.vocabulary.entry(term.clone()).or_insert_with(|| self.vocabulary.len());
            }
            term_freqs.push(term_count);
        }

        for term in self.vocabulary.keys() {
            let mut df = 0.0;
            for term_count in &term_freqs {
                if term_count.contains_key(term) {
                    df += 1.0;
                }
            }
            let idf_value = (doc_count + 1.0) / (df + 1.0);
            self.idf.insert(term.clone(), idf_value.ln() + 1.0);
        }

        let mut matrix = Vec::new();
        for term_count in term_freqs {
            let mut row = vec![0.0; self.vocabulary.len()];
            for (term, &count) in term_count.iter() {
                if let Some(&index) = self.vocabulary.get(term) {
                    let tf = (count as f64) / (term_count.values().sum::<usize>() as f64);
                    row[index] = tf * self.idf[term];
                }
            }
            matrix.push(row);
        }

        matrix
    }
}

fn process_text(data: Vec<&str>) -> Vec<Vec<f64>> {
    let mut vectorizer = TfidfVectorizer::new();
    vectorizer.fit_transform(data)
}

fn main() {
    let data = vec!["hello world", "data science", "python programming"];
    let result = process_text(data);
    for row in result {
        println!("{:?}", row);
    }
}