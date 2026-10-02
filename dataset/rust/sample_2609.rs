use ndarray::{Array1, arr1};

struct SequenceGenerator {
    length: usize,
}

impl SequenceGenerator {
    fn new(length: usize) -> Self {
        SequenceGenerator { length }
    }

    fn generate(&self) -> Array1<f64> {
        let mut sequence = Array1::zeros(self.length);
        for i in 1..self.length {
            sequence[i] = sequence[i - 1] + 0.5;
        }
        sequence
    }
}

struct FilterApplier {
    coefficients: Array1<f64>,
}

impl FilterApplier {
    fn new(coefficients: Array1<f64>) -> Self {
        FilterApplier { coefficients }
    }

    fn apply(&self, sequence: &Array1<f64>) -> Array1<f64> {
        let filtered_sequence = sequence.convolve(&self.coefficients, ndarray::ConvolveMode::Same);
        filtered_sequence
    }
}

struct SignalProcessor {
    generator: SequenceGenerator,
    filter: FilterApplier,
}

impl SignalProcessor {
    fn new(generator: SequenceGenerator, filter: FilterApplier) -> Self {
        SignalProcessor { generator, filter }
    }

    fn process(&self) -> Array1<f64> {
        let sequence = self.generator.generate();
        let filtered_sequence = self.filter.apply(&sequence);
        filtered_sequence
    }
}

fn main() {
    let length = 100;
    let coefficients = arr1(&[0.25, 0.5, 0.25]);
    let generator = SequenceGenerator::new(length);
    let filter_applier = FilterApplier::new(coefficients);
    let processor = SignalProcessor::new(generator, filter_applier);
    let result = processor.process();
    println!("{:?}", result);
}