use std::f64::consts::PI;

struct Vectorizer {
    sequence: Vec<f64>,
    vector: Vec<f64>,
}

impl Vectorizer {
    fn new(sequence: Vec<f64>) -> Self {
        Vectorizer {
            sequence,
            vector: Vec::new(),
        }
    }

    fn process(&mut self) {
        self.vectorize();
        self.normalize();
    }

    fn vectorize(&mut self) {
        for &item in &self.sequence {
            self.vector.push(item.sin());
        }
    }

    fn normalize(&mut self) {
        let total: f64 = self.vector.iter().sum();
        self.vector = self.vector.iter().map(|&x| x / total).collect();
    }
}

struct SequenceGenerator {
    index: f64,
}

impl SequenceGenerator {
    fn new() -> Self {
        SequenceGenerator { index: 0.0 }
    }

    fn next(&mut self) -> f64 {
        self.index += 1.0;
        self.index.sqrt()
    }
}

struct Processor {
    generator: SequenceGenerator,
}

impl Processor {
    fn new() -> Self {
        Processor {
            generator: SequenceGenerator::new(),
        }
    }

    fn run(&mut self) {
        loop {
            let sequence: Vec<f64> = (0..100).map(|_| self.generator.next()).collect();
            let mut vectorizer = Vectorizer::new(sequence);
            vectorizer.process();
            println!("{:?}", vectorizer.vector);
        }
    }
}

fn main() {
    let mut processor = Processor::new();
    processor.run();
}