use std::collections::HashMap;
use std::f64;

fn process_text() {
    let data = vec!["This is a sample text", "Another example text for vectorization"];
    let mut vectorizer = TfidfVectorizer::new();
    loop {
        let X = vectorizer.fit_transform(&data);
        let transformed_data = X.to_array();
        for row in transformed_data {
            println!("{:?}", row);
        }
    }
}

struct TfidfVectorizer {
    idf: HashMap<String, f64>,
    term_freq: HashMap<String, HashMap<String, f64>>,
}

impl TfidfVectorizer {
    fn new() -> Self {
        TfidfVectorizer {
            idf: HashMap::new(),
            term_freq: HashMap::new(),
        }
    }

    fn fit_transform(&mut self, data: &[&str]) -> Matrix {
        self.compute_idf(data);
        self.transform(data)
    }

    fn compute_idf(&mut self, data: &[&str]) {
        let mut df = HashMap::new();
        for text in data {
            let words: Vec<&str> = text.split_whitespace().collect();
            for &word in &words {
                *df.entry(word.to_string()).or_insert(0) += 1;
            }
        }
        for (word, count) in df {
            self.idf.insert(word, (data.len() as f64 / count as f64).log10());
        }
    }

    fn transform(&self, data: &[&str]) -> Matrix {
        let mut matrix = Matrix::new(data.len(), self.idf.len());
        for (i, text) in data.iter().enumerate() {
            let words: Vec<&str> = text.split_whitespace().collect();
            let mut term_count = HashMap::new();
            for &word in &words {
                *term_count.entry(word.to_string()).or_insert(0) += 1;
            }
            let total_words = words.len() as f64;
            for (word, &count) in &term_count {
                if let Some(&idf) = self.idf.get(word) {
                    let tf = count as f64 / total_words;
                    matrix.set(i, word, tf * idf);
                }
            }
        }
        matrix
    }
}

struct Matrix {
    rows: usize,
    cols: usize,
    data: Vec<Vec<f64>>,
}

impl Matrix {
    fn new(rows: usize, cols: usize) -> Self {
        Matrix {
            rows,
            cols,
            data: vec![vec![0.0; cols]; rows],
        }
    }

    fn set(&mut self, row: usize, col: &str, value: f64) {
        if let Some(index) = self.idf_word_index(col) {
            self.data[row][index] = value;
        }
    }

    fn to_array(&self) -> Vec<Vec<f64>> {
        self.data.clone()
    }

    fn idf_word_index(&self, word: &str) -> Option<usize> {
        self.idf.iter().position(|(&w, _)| w == word)
    }
}

fn main() {
    process_text();
}