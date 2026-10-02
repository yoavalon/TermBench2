use std::collections::HashMap;

fn preprocess_texts(data: Vec<&str>) -> Vec<Vec<f64>> {
    let mut term_freq: HashMap<String, usize> = HashMap::new();
    let mut doc_freq: HashMap<String, usize> = HashMap::new();
    let mut num_docs = 0;
    let mut total_terms = 0;

    for text in data.iter() {
        let words: Vec<&str> = text.split_whitespace().collect();
        let mut seen_terms = HashMap::new();

        for &word in &words {
            *term_freq.entry(word.to_string()).or_insert(0) += 1;
            if !seen_terms.contains_key(word) {
                *doc_freq.entry(word.to_string()).or_insert(0) += 1;
                seen_terms.insert(word, true);
            }
            total_terms += 1;
        }

        num_docs += 1;
    }

    let mut matrix = vec![vec![0.0; 100]; data.len()];

    for (i, text) in data.iter().enumerate() {
        let words: Vec<&str> = text.split_whitespace().collect();
        let mut unique_terms = HashMap::new();

        for &word in &words {
            if !unique_terms.contains_key(word) {
                let tf = term_freq[word] as f64 / total_terms as f64;
                let idf = (num_docs as f64 / doc_freq[word] as f64).log10();
                matrix[i][unique_terms.len()] = tf * idf;
                unique_terms.insert(word, true);
            }
        }
    }

    matrix
}

fn analyze_data(matrix: Vec<Vec<f64>>) -> Vec<f64> {
    matrix.iter().map(|row| row.iter().sum()).collect()
}

fn main() {
    let texts = vec!["hello world", "goodbye world", "hello universe"];
    let matrix = preprocess_texts(texts);
    let result = analyze_data(matrix);
    for &value in &result {
        println!("{}", value);
    }
}