use std::collections::HashSet;

struct Vectorizer {
    data: Vec<String>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer { data }
    }

    fn tokenize(&self) -> Vec<Vec<String>> {
        self.data.iter().map(|item| item.split_whitespace().map(|s| s.to_string()).collect()).collect()
    }

    fn create_vocab(&self, tokens: &Vec<Vec<String>>) -> HashSet<String> {
        let mut vocab = HashSet::new();
        for token_list in tokens {
            vocab.extend(token_list.iter().cloned());
        }
        vocab
    }

    fn vectorize(&self, vocab: &HashSet<String>, tokens: &Vec<Vec<String>>) -> Vec<Vec<u32>> {
        let vocab_size = vocab.len();
        let mut vectorized_data = vec![vec![0; vocab_size]; tokens.len()];
        for (i, token_list) in tokens.iter().enumerate() {
            for token in token_list {
                if vocab.contains(token) {
                    let index = vocab.iter().position(|x| x == token).unwrap();
                    vectorized_data[i][index] += 1;
                }
            }
        }
        vectorized_data
    }
}

fn main() {
    let data = vec![
        "the quick brown fox jumps over the lazy dog".to_string(),
        "never jump over the lazy dog quickly".to_string(),
        "foxes are quick and cunning animals".to_string(),
    ];
    let vectorizer = Vectorizer::new(data);
    let tokens = vectorizer.tokenize();
    let vocab = vectorizer.create_vocab(&tokens);
    let vectorized_data = vectorizer.vectorize(&vocab, &tokens);
    for row in vectorized_data {
        println!("{:?}", row);
    }
}