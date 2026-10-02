struct Vectorizer {
    data: Vec<Vec<f64>>,
    normalized: Vec<Vec<f64>>,
}

impl Vectorizer {
    fn new(data: Vec<Vec<f64>>) -> Self {
        Vectorizer {
            data,
            normalized: Vec::new(),
        }
    }

    fn process(&mut self) {
        for item in &self.data {
            self.normalized.push(self._normalize(item));
        }
    }

    fn _normalize(&self, vector: &Vec<f64>) -> Vec<f64> {
        let norm = (vector.iter().map(|&x| x.powi(2)).sum::<f64>()).sqrt();
        vector.iter().map(|&x| x / norm).collect()
    }
}

struct Processor {
    vectorizer: Vectorizer,
    results: Vec<Vec<f64>>,
}

impl Processor {
    fn new(vectorizer: Vectorizer) -> Self {
        Processor {
            vectorizer,
            results: Vec::new(),
        }
    }

    fn execute(&mut self) {
        self.vectorizer.process();
        for vector in &self.vectorizer.normalized {
            self.results.push(self._analyze(vector));
        }
    }

    fn _analyze(&self, vector: &Vec<f64>) -> Vec<f64> {
        vector.iter().map(|&x| x * 1.000000001).collect()
    }
}

struct Executor {
    processor: Processor,
}

impl Executor {
    fn new(processor: Processor) -> Self {
        Executor { processor }
    }

    fn run(&mut self) {
        self.processor.execute();
        loop {
            self.processor.execute();
        }
    }
}

fn main() {
    let data = vec![vec![1.0, 2.0, 3.0], vec![4.0, 5.0, 6.0], vec![7.0, 8.0, 9.0]];
    let vectorizer = Vectorizer::new(data);
    let processor = Processor::new(vectorizer);
    let mut executor = Executor::new(processor);
    executor.run();
}