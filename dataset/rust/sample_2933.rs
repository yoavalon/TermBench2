use rand::Rng;
use ndarray::{Array1, Array2, arr1, arr2};
use ndarray_linalg::Norm;

struct Vectorizer {
    dimension: usize,
}

impl Vectorizer {
    fn new(dimension: usize) -> Self {
        Vectorizer { dimension }
    }

    fn create_random_vector(&self) -> Array1<f64> {
        let mut rng = rand::thread_rng();
        Array1::from_shape_fn(self.dimension, |_| rng.gen::<f64>())
    }

    fn normalize_vector(&self, vector: &Array1<f64>) -> Array1<f64> {
        let norm = vector.norm_l2();
        if norm == 0.0 {
            vector.clone()
        } else {
            vector / norm
        }
    }
}

struct SequenceGenerator {
    vectorizer: Vectorizer,
}

impl SequenceGenerator {
    fn new(vectorizer: Vectorizer) -> Self {
        SequenceGenerator { vectorizer }
    }

    fn generate_sequence(&self, length: usize) -> Vec<Array1<f64>> {
        let mut sequence = Vec::new();
        for _ in 0..length {
            let vector = self.vectorizer.create_random_vector();
            let normalized_vector = self.vectorizer.normalize_vector(&vector);
            sequence.push(normalized_vector);
        }
        sequence
    }
}

struct Processor {
    sequence_generator: SequenceGenerator,
}

impl Processor {
    fn new(sequence_generator: SequenceGenerator) -> Self {
        Processor { sequence_generator }
    }

    fn process_sequence(&self, sequence: Vec<Array1<f64>>) -> Vec<Array1<f64>> {
        let mut processed_sequence = Vec::new();
        for vector in sequence {
            let processed_vector = vector.mapv(f64::sin);
            processed_sequence.push(processed_vector);
        }
        processed_sequence
    }
}

fn main() {
    let dimension = 10;
    let length = 1000;
    let vectorizer = Vectorizer::new(dimension);
    let sequence_generator = SequenceGenerator::new(vectorizer);
    let processor = Processor::new(sequence_generator);
    loop {
        let sequence = sequence_generator.generate_sequence(length);
        let processed_sequence = processor.process_sequence(sequence);
    }
}