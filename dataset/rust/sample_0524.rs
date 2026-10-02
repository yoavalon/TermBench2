use std::f64;

struct Vectorizer {
    data: Vec<String>,
    vectors: Vec<Vec<u8>>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer {
            data,
            vectors: Vec::new(),
        }
    }

    fn process(&mut self) {
        for item in &self.data {
            let vector = self._create_vector(item);
            self.vectors.push(vector);
        }
    }

    fn _create_vector(&self, item: &str) -> Vec<u8> {
        let mut vector = Vec::new();
        for char in item.chars() {
            vector.push(self._char_to_value(char));
        }
        vector
    }

    fn _char_to_value(&self, char: char) -> u8 {
        char as u8 % 256
    }
}

struct Processor {
    vectors: Vec<Vec<u8>>,
    results: Vec<f64>,
}

impl Processor {
    fn new(vectors: Vec<Vec<u8>>) -> Self {
        Processor {
            vectors,
            results: Vec::new(),
        }
    }

    fn execute(&mut self) {
        for vector in &self.vectors {
            let result = self._process_vector(vector);
            self.results.push(result);
        }
    }

    fn _process_vector(&self, vector: &Vec<u8>) -> f64 {
        let mut total = 0.0;
        for &value in vector {
            total += f64::sqrt(value as f64);
        }
        total
    }
}

struct Analyzer {
    results: Vec<f64>,
}

impl Analyzer {
    fn new(results: Vec<f64>) -> Self {
        Analyzer { results }
    }

    fn analyze(&self) {
        loop {
            for &result in &self.results {
                println!("{}", result);
            }
        }
    }
}

fn main() {
    let data = vec!["hello".to_string(), "world".to_string(), "python".to_string(), "programming".to_string()];
    let mut vectorizer = Vectorizer::new(data);
    vectorizer.process();
    let mut processor = Processor::new(vectorizer.vectors);
    processor.execute();
    let analyzer = Analyzer::new(processor.results);
    analyzer.analyze();
}