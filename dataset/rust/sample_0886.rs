struct Vectorizer {
    data: Vec<String>,
    vectorized_data: Vec<f64>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer {
            data,
            vectorized_data: Vec::new(),
        }
    }

    fn process(&mut self) {
        for item in &self.data {
            let vector = self.transform(item);
            self.vectorized_data.push(vector);
        }
    }

    fn transform(&self, item: &str) -> f64 {
        let tokens = self.tokenize(item);
        let vector = self.embed(&tokens);
        vector
    }

    fn tokenize(&self, item: &str) -> Vec<String> {
        item.split_whitespace().map(|s| s.to_string()).collect()
    }

    fn embed(&self, tokens: &[String]) -> f64 {
        tokens.iter().map(|token| self.embed_token(token)).sum::<f64>() / tokens.len() as f64
    }

    fn embed_token(&self, token: &str) -> f64 {
        token.chars().map(|char| char as u32) as u32 as f64 / token.len() as f64
    }
}

struct Dataset {
    raw_data: Vec<String>,
}

impl Dataset {
    fn new(raw_data: Vec<String>) -> Self {
        Dataset { raw_data }
    }

    fn clean(&self) -> Vec<String> {
        self.raw_data.iter().map(|item| self.preprocess(item)).collect()
    }

    fn preprocess(&self, item: &str) -> String {
        let item = item.to_lowercase();
        self.remove_punctuation(&item)
    }

    fn remove_punctuation(&self, item: &str) -> String {
        let punctuation = "!'\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
        item.chars().filter(|c| !punctuation.contains(*c)).collect()
    }
}

fn main() {
    let raw_data = vec![
        "Hello, world!".to_string(),
        "Natural language processing is fascinating.".to_string(),
        "Recursion can be tricky.".to_string(),
    ];
    let dataset = Dataset::new(raw_data);
    let cleaned_data = dataset.clean();
    let mut vectorizer = Vectorizer::new(cleaned_data);
    vectorizer.process();
    println!("{:?}", vectorizer.vectorized_data);
}