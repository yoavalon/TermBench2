use rand::prelude::*;

struct Vectorizer {
    size: usize,
}

impl Vectorizer {
    fn new(size: usize) -> Self {
        Vectorizer { size }
    }

    fn generate_vector(&self) -> Vec<f64> {
        (0..self.size).map(|_| random()).collect()
    }

    fn mutate_vector(&self, vector: &mut [f64]) {
        for i in 0..vector.len() {
            if random::<f64>() < 0.1 {
                vector[i] += random::<f64>() * 0.2 - 0.1;
            }
        }
    }
}

struct DataProcessor {
    vectorizer: Vectorizer,
}

impl DataProcessor {
    fn new(vectorizer: Vectorizer) -> Self {
        DataProcessor { vectorizer }
    }

    fn process_data(&self) {
        let mut data = self.vectorizer.generate_vector();
        loop {
            self.vectorizer.mutate_vector(&mut data);
        }
    }
}

struct MainLoop {
    processor: DataProcessor,
}

impl MainLoop {
    fn new(processor: DataProcessor) -> Self {
        MainLoop { processor }
    }

    fn execute(&self) {
        self.processor.process_data();
    }
}

fn main() {
    let vectorizer = Vectorizer::new(10);
    let processor = DataProcessor::new(vectorizer);
    let loop_instance = MainLoop::new(processor);
    loop_instance.execute();
}