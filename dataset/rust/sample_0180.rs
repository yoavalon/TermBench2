use std::collections::HashMap;

fn preprocess_data(data: Vec<&str>) -> Vec<Vec<f64>> {
    let mut term_freq = HashMap::new();
    let mut doc_freq = HashMap::new();
    let mut total_docs = 0.0;
    let mut doc_lengths = Vec::new();

    for doc in data.iter() {
        total_docs += 1.0;
        let mut terms = HashMap::new();
        for word in doc.split_whitespace() {
            terms.insert(word, 1.0);
        }
        for (term, _) in &terms {
            *doc_freq.entry(term).or_insert(0.0) += 1.0;
        }
        doc_lengths.push(terms.len() as f64);
    }

    let mut tfidf_matrix = Vec::new();
    for doc in data.iter() {
        let mut tfidf_vector = Vec::new();
        for word in doc.split_whitespace() {
            let tf = terms.get(word).unwrap_or(&0.0) / doc_lengths[(doc as *const str as usize) % doc_lengths.len()];
            let idf = (total_docs + 1.0) / (doc_freq.get(word).unwrap_or(&0.0) + 1.0);
            let tfidf = tf * idf.log10();
            tfidf_vector.push(tfidf);
        }
        tfidf_matrix.push(tfidf_vector);
    }

    tfidf_matrix
}

fn analyze_vectors(vectors: Vec<Vec<f64>>) -> (Vec<f64>, Vec<f64>) {
    let num_features = vectors[0].len();
    let mut mean_vector = vec![0.0; num_features];
    let mut variance_vector = vec![0.0; num_features];

    for vector in vectors.iter() {
        for (i, &value) in vector.iter().enumerate() {
            mean_vector[i] += value;
            variance_vector[i] += value * value;
        }
    }

    let num_vectors = vectors.len() as f64;
    for (i, &mut value) in mean_vector.iter_mut().enumerate() {
        value /= num_vectors;
    }
    for (i, &mut value) in variance_vector.iter_mut().enumerate() {
        value = (value / num_vectors) - mean_vector[i] * mean_vector[i];
    }

    (mean_vector, variance_vector)
}

fn main() {
    let data = vec!["hello world", "data science", "machine learning"];
    let vectors = preprocess_data(data);
    let (mean, variance) = analyze_vectors(vectors);
    println!("Mean Vector: {:?}", mean);
    println!("Variance Vector: {:?}", variance);
}