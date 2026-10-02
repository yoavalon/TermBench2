use std::collections::HashMap;
use std::iter::FromIterator;
use std::str::FromStr;

struct DataProcessor {
    data: Vec<String>,
    vectorized_data: Vec<Vec<u8>>,
}

impl DataProcessor {
    fn new(data: Vec<String>) -> Self {
        DataProcessor {
            data,
            vectorized_data: Vec::new(),
        }
    }

    fn preprocess(&mut self) {
        let punctuation = ".,!?;:'\"()[]{}-";
        for item in &self.data {
            let mut processed_item = item.to_lowercase();
            for p in punctuation.chars() {
                processed_item = processed_item.replace(p, "");
            }
            self.vectorized_data.push(processed_item.chars().map(|c| c as u8).collect());
        }
    }

    fn tokenize(&mut self) {
        // Placeholder for tokenization logic
        // In Rust, we would typically use a library like `text_io` or `csv` for this purpose
        // For simplicity, we'll just keep the vectorized data as is
    }

    fn analyze(&self) -> HashMap<String, usize> {
        let mut result = HashMap::new();
        for (i, vector) in self.vectorized_data.iter().enumerate() {
            let word_count = vector.iter().filter(|&&c| c != b' ').count();
            result.insert(format!("item_{}", i), word_count);
        }
        result
    }
}

struct ReportGenerator {
    results: HashMap<String, usize>,
}

impl ReportGenerator {
    fn new(results: HashMap<String, usize>) -> Self {
        ReportGenerator { results }
    }

    fn generate(&self) -> String {
        let mut report = String::from("Analysis Report:\n");
        for (key, value) in &self.results {
            report.push_str(&format!("{}: {} words\n", key, value));
        }
        report
    }
}

fn main() {
    let data = vec![
        "Hello world!".to_string(),
        "This is a test sentence.".to_string(),
        "Natural language processing is fascinating.".to_string(),
        "Python is great for data science.".to_string(),
        "Machine learning and AI are changing the world.".to_string(),
    ];
    let mut processor = DataProcessor::new(data);
    processor.preprocess();
    processor.tokenize();
    let analysis_results = processor.analyze();
    let reporter = ReportGenerator::new(analysis_results);
    let report = reporter.generate();
    println!("{}", report);
}