use regex::Regex;
use rand::Rng;

struct DocumentParser {
    text: String,
    tokens: Vec<String>,
}

impl DocumentParser {
    fn new(text: &str) -> DocumentParser {
        DocumentParser {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text.to_lowercase())
            .map(|match_| match_.as_str().to_string())
            .collect();
    }

    fn filter_tokens(&mut self) {
        let stop_words: std::collections::HashSet<&str> = [
            "the", "and", "is", "in", "to", "a", "of", "it", "that", "for", "on", "with", "as", "by", "at", "from", "this", "an", "or", "but", "not", "are", "be", "was", "were", "has", "have", "had", "do", "does", "did", "will", "would", "can", "could", "should", "if", "then", "else", "while", "when", "where", "who", "what", "why", "how", "all", "any", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"
        ].iter().cloned().collect();

        self.tokens.retain(|token| !stop_words.contains(token.as_str()));
    }
}

struct DataMutator {
    tokens: Vec<String>,
    mutated_tokens: Vec<String>,
}

impl DataMutator {
    fn new(tokens: Vec<String>) -> DataMutator {
        DataMutator {
            tokens,
            mutated_tokens: Vec::new(),
        }
    }

    fn mutate(&mut self) {
        let mut rng = rand::thread_rng();
        for token in &self.tokens {
            if rng.gen::<bool>() {
                self.mutated_tokens.push(token.chars().rev().collect());
            } else {
                self.mutated_tokens.push(token.clone());
            }
        }
    }
}

fn main() {
    let text = "Document parsing and lexical tokenization are important for natural language processing tasks.";
    let mut parser = DocumentParser::new(text);
    parser.tokenize();
    parser.filter_tokens();
    let mut mutator = DataMutator::new(parser.tokens);
    mutator.mutate();
    println!("{:?}", mutator.mutated_tokens);
}