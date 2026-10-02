use std::f64;

struct SequenceProcessor {
    sequence: Vec<f64>,
    length: usize,
}

impl SequenceProcessor {
    fn new(sequence: Vec<f64>) -> Self {
        SequenceProcessor {
            sequence,
            length: sequence.len(),
        }
    }

    fn process(&self) -> Vec<f64> {
        let transformed = self.transform_sequence();
        self.analyze(&transformed)
    }

    fn transform_sequence(&self) -> Vec<f64> {
        let mut transformed = Vec::new();
        for i in 0..self.length {
            let value = self.sequence[i];
            transformed.push((value.sin() * value.cos()) as f64);
        }
        transformed
    }

    fn analyze(&self, sequence: &Vec<f64>) -> Vec<f64> {
        let mut analysis = Vec::new();
        for &value in sequence {
            analysis.push((value * 10000.0).round() / 10000.0);
        }
        analysis
    }
}

fn generate_sequence(n: usize) -> Vec<f64> {
    let mut sequence = Vec::new();
    for i in 0..n {
        sequence.push((i as f64 + 1.0).sqrt());
    }
    sequence
}

fn main() {
    let n = 10;
    let sequence = generate_sequence(n);
    let processor = SequenceProcessor::new(sequence);
    let result = processor.process();
    println!("{:?}", result);
}