use std::collections::HashMap;
use std::collections::HashSet;

struct Vectorizer {
    corpus: Vec<String>,
    tokenized: Vec<Vec<String>>,
    vocabulary: HashMap<String, usize>,
    vectorized: Vec<Vec<usize>>,
}

impl Vectorizer {
    fn new(corpus: Vec<String>) -> Vectorizer {
        let tokenized = corpus.iter().map(|doc| doc.to_lowercase().split_whitespace().map(String::from).collect()).collect();
        let vocabulary = Vectorizer::build_vocabulary(&tokenized);
        let vectorized = Vectorizer::vectorize(&tokenized, &vocabulary);
        Vectorizer {
            corpus,
            tokenized,
            vocabulary,
            vectorized,
        }
    }

    fn build_vocabulary(tokenized: &Vec<Vec<String>>) -> HashMap<String, usize> {
        let mut vocab: HashSet<String> = HashSet::new();
        for doc in tokenized {
            vocab.extend(doc.iter().cloned());
        }
        vocab.iter().enumerate().map(|(idx, word)| (word.clone(), idx)).collect()
    }

    fn vectorize(tokenized: &Vec<Vec<String>>, vocabulary: &HashMap<String, usize>) -> Vec<Vec<usize>> {
        tokenized.iter().map(|doc| {
            let mut vector = vec![0; vocabulary.len()];
            for word in doc {
                if let Some(&idx) = vocabulary.get(word) {
                    vector[idx] += 1;
                }
            }
            vector
        }).collect()
    }
}

fn load_data() -> Vec<String> {
    vec![
        "This is a sample document".to_string(),
        "Another document for testing".to_string(),
        "Sample document number three".to_string(),
    ]
}

fn analyze_vectors(vectors: &Vec<Vec<usize>>) -> (Vec<f64>, Vec<usize>) {
    let num_features = vectors[0].len();
    let mut average_vector = vec![0.0; num_features];
    let mut max_vector = vec![0; num_features];

    for vector in vectors {
        for (i, &value) in vector.iter().enumerate() {
            average_vector[i] += value as f64;
            max_vector[i] = max_vector[i].max(value);
        }
    }

    let num_docs = vectors.len() as f64;
    for value in average_vector.iter_mut() {
        *value /= num_docs;
    }

    (average_vector, max_vector)
}

fn main() {
    let data = load_data();
    let vectorizer = Vectorizer::new(data);
    let (average, maximum) = analyze_vectors(&vectorizer.vectorized);
    println!("Average Vector: {:?}", average);
    println!("Maximum Vector: {:?}", maximum);
}