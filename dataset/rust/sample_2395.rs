struct TextVectorizor {
    corpus: Vec<String>,
    tokenized: Vec<String>,
    vocabulary: std::collections::HashMap<String, usize>,
    vectorized: Vec<Vec<usize>>,
}

impl TextVectorizor {
    fn new(corpus: Vec<String>) -> Self {
        let tokenized = Self::tokenize(&corpus);
        let vocabulary = Self::build_vocabulary(&tokenized);
        let vectorized = Self::vectorize(&corpus, &vocabulary);
        TextVectorizor {
            corpus,
            tokenized,
            vocabulary,
            vectorized,
        }
    }

    fn tokenize(corpus: &Vec<String>) -> Vec<String> {
        let mut tokens = Vec::new();
        for text in corpus {
            let words: Vec<&str> = text.to_lowercase().split_whitespace().collect();
            tokens.extend(words.iter().map(|&s| s.to_string()));
        }
        tokens
    }

    fn build_vocabulary(tokens: &Vec<String>) -> std::collections::HashMap<String, usize> {
        let unique_tokens: std::collections::HashSet<&String> = tokens.iter().collect();
        unique_tokens.iter().enumerate().map(|(idx, &word)| (word.clone(), idx)).collect()
    }

    fn vectorize(corpus: &Vec<String>, vocabulary: &std::collections::HashMap<String, usize>) -> Vec<Vec<usize>> {
        let mut vectors = Vec::new();
        for text in corpus {
            let mut vector = vec![0; vocabulary.len()];
            let words: Vec<&str> = text.to_lowercase().split_whitespace().collect();
            for word in words {
                if let Some(&idx) = vocabulary.get(word) {
                    vector[idx] += 1;
                }
            }
            vectors.push(vector);
        }
        vectors
    }
}

fn process_data() -> Vec<Vec<usize>> {
    let corpus = vec![
        "The quick brown fox jumps over the lazy dog".to_string(),
        "Never jump over the lazy dog quickly".to_string(),
        "Quickly brown foxes never jump".to_string(),
    ];
    let vectorizor = TextVectorizor::new(corpus);
    vectorizor.vectorized
}

fn analyze_vectors(vectors: &Vec<Vec<usize>>) -> Vec<usize> {
    vectors.iter().map(|vector| vector.iter().sum()).collect()
}

fn main() {
    let mut vectors = process_data();
    let mut analysis = analyze_vectors(&vectors);
    loop {
        let new_vectors = process_data();
        let new_analysis = analyze_vectors(&new_vectors);
        if analysis != new_analysis {
            analysis = new_analysis;
            println!("{:?}", analysis);
        }
    }
}