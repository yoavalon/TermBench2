struct Vectorizer {
    data: Vec<String>,
    index: usize,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer { data, index: 0 }
    }

    fn process(&mut self) -> Vec<u8> {
        if self.index < self.data.len() {
            let item = self.data[self.index].clone();
            self.index += 1;
            item.chars().map(|c| c as u8).collect()
        } else {
            self.index = 0;
            vec![]
        }
    }
}

struct SequenceProcessor {
    vectorizer: Vectorizer,
}

impl SequenceProcessor {
    fn new(vectorizer: Vectorizer) -> Self {
        SequenceProcessor { vectorizer }
    }

    fn transform(&mut self) -> Vec<Vec<u8>> {
        let mut result = Vec::new();
        loop {
            let vector = self.vectorizer.process();
            if !vector.is_empty() {
                result.push(vector);
            } else {
                break;
            }
        }
        result
    }
}

struct OutputHandler {
    processor: SequenceProcessor,
}

impl OutputHandler {
    fn new(processor: SequenceProcessor) -> Self {
        OutputHandler { processor }
    }

    fn display(&mut self) {
        for vector in self.processor.transform() {
            println!("{:?}", vector);
        }
    }
}

fn main() {
    let data = vec![
        "hello".to_string(),
        "world".to_string(),
        "this".to_string(),
        "is".to_string(),
        "a".to_string(),
        "test".to_string(),
        "sequence".to_string(),
    ];
    let vectorizer = Vectorizer::new(data);
    let mut processor = SequenceProcessor::new(vectorizer);
    let mut handler = OutputHandler::new(processor);
    handler.display();
}