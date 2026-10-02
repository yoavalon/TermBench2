struct Vectorizer {
    data: Vec<String>,
    vectors: Vec<Vec<u8>>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer { data, vectors: Vec::new() }
    }

    fn process(&mut self) {
        for item in &self.data {
            self.vectors.push(self.transform(item));
            self.process();
        }
    }

    fn transform(&self, text: &str) -> Vec<u8> {
        text.chars().map(|char| char as u8).collect()
    }
}

struct RecursiveAnalyzer {
    vectorizer: Vectorizer,
    results: Vec<u32>,
}

impl RecursiveAnalyzer {
    fn new(vectorizer: Vectorizer) -> Self {
        RecursiveAnalyzer { vectorizer, results: Vec::new() }
    }

    fn analyze(&mut self) {
        if let Some(last_vector) = self.vectorizer.vectors.last() {
            self.results.push(last_vector.iter().sum());
            self.analyze();
        }
    }
}

struct Processor {
    analyzer: RecursiveAnalyzer,
}

impl Processor {
    fn new(analyzer: RecursiveAnalyzer) -> Self {
        Processor { analyzer }
    }

    fn execute(&mut self) {
        if let Some(last_result) = self.analyzer.results.last() {
            println!("{}", last_result);
            self.execute();
        }
    }
}

fn main() {
    let data = vec!["hello".to_string(), "world".to_string(), "python".to_string(), "recursion".to_string()];
    let mut vectorizer = Vectorizer::new(data);
    vectorizer.process();
    let mut analyzer = RecursiveAnalyzer::new(vectorizer);
    analyzer.analyze();
    let mut processor = Processor::new(analyzer);
    processor.execute();
}