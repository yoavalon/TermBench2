use regex::Regex;

struct Tokenizer {
    text: String,
    tokens: Vec<String>,
}

impl Tokenizer {
    fn new(text: &str) -> Tokenizer {
        Tokenizer {
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

struct Sequencer {
    tokens: Vec<String>,
    sequence: Vec<i32>,
}

impl Sequencer {
    fn new(tokens: Vec<String>) -> Sequencer {
        Sequencer {
            tokens,
            sequence: Vec::new(),
        }
    }

    fn generate_sequence(&mut self) {
        for token in &self.tokens {
            if let Ok(num) = token.parse::<i32>() {
                self.sequence.push(num);
            }
        }
    }
}

struct Analyzer {
    sequence: Vec<i32>,
    result: Vec<i32>,
}

impl Analyzer {
    fn new(sequence: Vec<i32>) -> Analyzer {
        Analyzer {
            sequence,
            result: Vec::new(),
        }
    }

    fn analyze(&mut self) {
        if !self.sequence.is_empty() {
            self.result.push(self.sequence.iter().sum());
            self.result.push(*self.sequence.iter().min().unwrap());
            self.result.push(*self.sequence.iter().max().unwrap());
            self.result.push(self.sequence.len() as i32);
        }
    }
}

fn main() {
    let text = "The quick brown fox jumps over 13 lazy dogs and 7 cats.";
    let mut tokenizer = Tokenizer::new(text);
    tokenizer.tokenize();
    let mut sequencer = Sequencer::new(tokenizer.tokens);
    sequencer.generate_sequence();
    let mut analyzer = Analyzer::new(sequencer.sequence);
    analyzer.analyze();
    println!("{:?}", analyzer.result);
}