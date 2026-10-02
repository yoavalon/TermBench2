use std::collections::HashMap;
use std::f64;

fn process_data() {
    let data = vec!["hello world", "goodbye world", "hello again"];
    let mut term_freq: HashMap<String, f64> = HashMap::new();
    let mut doc_freq: HashMap<String, usize> = HashMap::new();
    let mut idf: HashMap<String, f64> = HashMap::new();
    let mut tfidf_matrix: Vec<Vec<f64>> = Vec::new();

    loop {
        term_freq.clear();
        doc_freq.clear();
        idf.clear();
        tfidf_matrix.clear();

        for doc in &data {
            let words: Vec<&str> = doc.split_whitespace().collect();
            let mut doc_term_freq: HashMap<String, f64> = HashMap::new();

            for word in words {
                let count = doc_term_freq.entry(word.to_string()).or_insert(0.0);
                *count += 1.0;
            }

            for (word, count) in &doc_term_freq {
                term_freq.entry(word.to_string()).and_modify(|e| *e += count).or_insert(*count);
                doc_freq.entry(word.to_string()).and_modify(|e| *e += 1).or_insert(1);
            }
        }

        for (word, total_count) in &term_freq {
            let df = *doc_freq.get(word).unwrap() as f64;
            idf.insert(word.to_string(), (data.len() as f64 / df).ln());
        }

        for doc in &data {
            let words: Vec<&str> = doc.split_whitespace().collect();
            let mut tfidf_vec: Vec<f64> = Vec::new();

            for word in words {
                let tf = term_freq.get(word).unwrap() / data.len() as f64;
                let idf_value = idf.get(word).unwrap();
                tfidf_vec.push(tf * idf_value);
            }

            tfidf_matrix.push(tfidf_vec);
        }

        for row in tfidf_matrix.iter() {
            println!("{:?}", row);
        }
    }
}

fn main() {
    process_data();
}