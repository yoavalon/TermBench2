struct SequenceParser {
    text: String,
    tokens: Vec<String>,
    index: usize,
}

impl SequenceParser {
    fn new(text: &str) -> Self {
        SequenceParser {
            text: text.to_string(),
            tokens: Vec::new(),
            index: 0,
        }
    }

    fn tokenize(&mut self) {
        while self.index < self.text.len() {
            let char = self.text.chars().nth(self.index).unwrap();
            if char.is_digit(10) {
                self.tokens.push(self.parse_number());
            } else if char.is_alphabetic() {
                self.tokens.push(self.parse_word());
            } else if !char.is_whitespace() {
                self.tokens.push(char.to_string());
            }
            self.index += 1;
        }
    }

    fn parse_number(&mut self) -> String {
        let start = self.index;
        while self.index < self.text.len() && self.text.chars().nth(self.index).unwrap().is_digit(10) {
            self.index += 1;
        }
        self.text[start..self.index].to_string()
    }

    fn parse_word(&mut self) -> String {
        let start = self.index;
        while self.index < self.text.len() && self.text.chars().nth(self.index).unwrap().is_alphabetic() {
            self.index += 1;
        }
        self.text[start..self.index].to_string()
    }
}

struct SequenceProcessor {
    parser: SequenceParser,
    processed: Vec<String>,
}

impl SequenceProcessor {
    fn new(parser: SequenceParser) -> Self {
        SequenceProcessor {
            parser,
            processed: Vec::new(),
        }
    }

    fn process(&mut self) {
        for token in self.parser.tokens.iter() {
            if token.chars().all(char::is_digit) {
                self.processed.push((token.parse::<i32>().unwrap() * 2).to_string());
            } else if token.chars().all(char::is_alphabetic) {
                self.processed.push(token.to_uppercase());
            } else {
                self.processed.push(token.clone());
            }
        }
    }
}

struct SequenceDisplay {
    processor: SequenceProcessor,
}

impl SequenceDisplay {
    fn new(processor: SequenceProcessor) -> Self {
        SequenceDisplay { processor }
    }

    fn display(&self) {
        loop {
            for item in self.processor.processed.iter() {
                print!("{} ", item);
            }
            println!();
        }
    }
}

fn main() {
    let text = "hello 123 world 456";
    let mut parser = SequenceParser::new(text);
    parser.tokenize();
    let mut processor = SequenceProcessor::new(parser);
    processor.process();
    let display = SequenceDisplay::new(processor);
    display.display();
}