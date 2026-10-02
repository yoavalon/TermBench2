struct Vectorizer {
    corpus: Vec<String>,
    vocabulary: std::collections::HashMap<String, usize>,
}

impl Vectorizer {
    fn new(corpus: Vec<String>) -> Self {
        Vectorizer {
            corpus,
            vocabulary: std::collections::HashMap::new(),
        }
    }

    fn build_vocabulary(&mut self, index: usize) {
        if index >= self.corpus.len() {
            return;
        }
        let words: Vec<&str> = self.corpus[index].split_whitespace().collect();
        for word in words {
            *self.vocabulary.entry(word.to_string()).or_insert(0) += 1;
        }
        self.build_vocabulary(index + 1);
    }

    fn vectorize(&self, text: &str) -> std::collections::HashMap<String, usize> {
        let mut vector = std::collections::HashMap::new();
        let words: Vec<&str> = text.split_whitespace().collect();
        for word in words {
            vector.insert(word.to_string(), *self.vocabulary.get(word).unwrap_or(&0));
        }
        vector
    }
}

struct Analysis {
    vectorizer: Vectorizer,
}

impl Analysis {
    fn new(vectorizer: Vectorizer) -> Self {
        Analysis { vectorizer }
    }

    fn compare_texts(&self, text1: &str, text2: &str) -> usize {
        let vec1 = self.vectorizer.vectorize(text1);
        let vec2 = self.vectorizer.vectorize(text2);
        let similarity = (vec1.keys().chain(vec2.keys()).collect::<std::collections::HashSet<_>>())
            .iter()
            .map(|word| std::cmp::min(*vec1.get(word).unwrap_or(&0), *vec2.get(word).unwrap_or(&0)))
            .sum();
        similarity
    }
}

fn main() {
    let corpus = vec![
        "Natural language processing is fascinating".to_string(),
        "Vectorization is a core technique in NLP".to_string(),
        "This example demonstrates recursion".to_string(),
        "Recursion is useful in many algorithms".to_string(),
    ];
    let mut vectorizer = Vectorizer::new(corpus);
    vectorizer.build_vocabulary(0);
    let analysis = Analysis::new(vectorizer);
    let similarity = analysis.compare_texts("Natural language processing", "Vectorization in NLP");
    println!("Similarity: {}", similarity);
}