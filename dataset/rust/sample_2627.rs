use regex::Regex;
use std::collections::HashMap;

struct TextProcessor {
    text: String,
    tokens: Vec<String>,
}

impl TextProcessor {
    fn new(text: &str) -> Self {
        TextProcessor {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text.to_lowercase())
            .map(|mat| mat.as_str().to_string())
            .collect();
    }
}

struct SequenceAnalyzer {
    tokens: Vec<String>,
    sequences: HashMap<(String, String), usize>,
}

impl SequenceAnalyzer {
    fn new(tokens: Vec<String>) -> Self {
        SequenceAnalyzer {
            tokens,
            sequences: HashMap::new(),
        }
    }

    fn identify_sequences(&mut self) {
        for i in 0..self.tokens.len() - 1 {
            let pair = (self.tokens[i].clone(), self.tokens[i + 1].clone());
            *self.sequences.entry(pair).or_insert(0) += 1;
        }
    }
}

struct ReportGenerator {
    sequences: HashMap<(String, String), usize>,
}

impl ReportGenerator {
    fn new(sequences: HashMap<(String, String), usize>) -> Self {
        ReportGenerator { sequences }
    }

    fn generate_report(&self) -> Vec<((String, String), usize)> {
        let mut report: Vec<_> = self.sequences.iter().collect();
        report.sort_by(|a, b| b.1.cmp(&a.1));
        report
    }
}

fn main() {
    let text = "This is a test text for parsing and tokenization. We will test the text processing and sequence analysis.";
    let mut processor = TextProcessor::new(text);
    processor.tokenize();
    let mut analyzer = SequenceAnalyzer::new(processor.tokens);
    analyzer.identify_sequences();
    let generator = ReportGenerator::new(analyzer.sequences);
    let report = generator.generate_report();
    for ((sequence1, sequence2), count) in report.iter().take(10) {
        println!("Sequence: ({}, {}), Count: {}", sequence1, sequence2, count);
    }
}