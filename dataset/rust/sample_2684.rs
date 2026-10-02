use regex::Regex;

struct SequenceTokenizer {
    text: String,
    tokens: Vec<String>,
}

impl SequenceTokenizer {
    fn new(text: &str) -> Self {
        SequenceTokenizer {
            text: text.to_string(),
            tokens: Vec::new(),
        }
    }

    fn tokenize(&mut self) {
        let re = Regex::new(r"\b\w+\b").unwrap();
        self.tokens = re.find_iter(&self.text)
                         .map(|mat| mat.as_str().to_string())
                         .collect();
    }
}

struct SequenceAnalyzer {
    tokens: Vec<String>,
    math_sequences: Vec<String>,
}

impl SequenceAnalyzer {
    fn new(tokens: Vec<String>) -> Self {
        SequenceAnalyzer {
            tokens,
            math_sequences: Vec::new(),
        }
    }

    fn analyze(&mut self) {
        for token in &self.tokens {
            if self.is_math_sequence(token) {
                self.math_sequences.push(token.clone());
            }
        }
    }

    fn is_math_sequence(&self, token: &str) -> bool {
        token.split(',')
             .map(|s| s.trim().parse::<i32>())
             .collect::<Result<Vec<i32>, _>>()
             .map_or(false, |sequence| {
                 self.is_arithmetic(&sequence) || self.is_geometric(&sequence)
             })
    }

    fn is_arithmetic(&self, sequence: &[i32]) -> bool {
        if sequence.len() < 2 {
            return false;
        }
        let diff = sequence[1] - sequence[0];
        sequence[2..]
             .iter()
             .zip(sequence[1..].iter())
             .all(|(a, b)| a - b == diff)
    }

    fn is_geometric(&self, sequence: &[i32]) -> bool {
        if sequence.len() < 2 || sequence[0] == 0 {
            return false;
        }
        let ratio = sequence[1] as f64 / sequence[0] as f64;
        sequence[2..]
             .iter()
             .zip(sequence[1..].iter())
             .all(|(a, b)| (a as f64 / b as f64) == ratio)
    }
}

struct SequenceProcessor {
    sequences: Vec<String>,
}

impl SequenceProcessor {
    fn new(sequences: Vec<String>) -> Self {
        SequenceProcessor { sequences }
    }

    fn process(&self) -> Vec<String> {
        self.sequences
            .iter()
            .map(|sequence| self.classify_sequence(sequence))
            .collect()
    }

    fn classify_sequence(&self, sequence: &str) -> String {
        let sequence_list: Result<Vec<i32>, _> = sequence.split(',')
                                                        .map(|s| s.trim().parse::<i32>())
                                                        .collect();
        match sequence_list {
            Ok(sequence) if self.is_arithmetic(&sequence) => "Arithmetic".to_string(),
            Ok(sequence) if self.is_geometric(&sequence) => "Geometric".to_string(),
            _ => "Unknown".to_string(),
        }
    }

    fn is_arithmetic(&self, sequence: &[i32]) -> bool {
        if sequence.len() < 2 {
            return false;
        }
        let diff = sequence[1] - sequence[0];
        sequence[2..]
             .iter()
             .zip(sequence[1..].iter())
             .all(|(a, b)| a - b == diff)
    }

    fn is_geometric(&self, sequence: &[i32]) -> bool {
        if sequence.len() < 2 || sequence[0] == 0 {
            return false;
        }
        let ratio = sequence[1] as f64 / sequence[0] as f64;
        sequence[2..]
             .iter()
             .zip(sequence[1..].iter())
             .all(|(a, b)| (a as f64 / b as f64) == ratio)
    }
}

fn main() {
    let text = "Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively.";
    let mut tokenizer = SequenceTokenizer::new(text);
    tokenizer.tokenize();
    let mut analyzer = SequenceAnalyzer::new(tokenizer.tokens);
    analyzer.analyze();
    let processor = SequenceProcessor::new(analyzer.math_sequences);
    let results = processor.process();
    for result in results {
        println!("{}", result);
    }
}