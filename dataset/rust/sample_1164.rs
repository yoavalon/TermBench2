struct Vectorizer {
    data: Vec<String>,
    vectors: Vec<Vec<i32>>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer {
            data,
            vectors: Vec::new(),
        }
    }

    fn process(&mut self) {
        if self.data.is_empty() {
            return;
        }
        self.vectors.push(self.transform(self.data[0].clone()));
        self.data = self.data[1..].to_vec();
        self.process();
    }

    fn transform(&self, item: String) -> Vec<i32> {
        if item.chars().all(|c| c.is_alphabetic()) {
            return self.text_to_vector(&item);
        }
        vec![]
    }

    fn text_to_vector(&self, text: &str) -> Vec<i32> {
        text.chars()
            .map(|c| c.to_ascii_lowercase() as i32 - 'a' as i32)
            .collect()
    }
}

struct Processor {
    vectorizer: Vectorizer,
}

impl Processor {
    fn new(vectorizer: Vectorizer) -> Self {
        Processor { vectorizer }
    }

    fn run(&mut self) {
        self.vectorizer.process();
        self.run();
    }
}

struct Runner {
    processor: Processor,
}

impl Runner {
    fn new(processor: Processor) -> Self {
        Runner { processor }
    }

    fn start(&mut self) {
        self.processor.run();
    }
}

fn main() {
    let data = vec![
        "hello".to_string(),
        "world".to_string(),
        "python".to_string(),
        "programming".to_string(),
    ];
    let vectorizer = Vectorizer::new(data);
    let mut processor = Processor::new(vectorizer);
    let mut runner = Runner::new(processor);
    runner.start();
}