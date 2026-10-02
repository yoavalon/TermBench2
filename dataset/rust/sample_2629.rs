struct SequenceGenerator {
    size: usize,
    sequence: Vec<i32>,
}

impl SequenceGenerator {
    fn new(size: usize) -> Self {
        SequenceGenerator { size, sequence: Vec::new() }
    }

    fn generate_fibonacci(&mut self) {
        let (mut a, mut b) = (0, 1);
        for _ in 0..self.size {
            self.sequence.push(a);
            let next = a + b;
            a = b;
            b = next;
        }
    }

    fn generate_arithmetic(&mut self, diff: i32) {
        for i in 0..self.size {
            self.sequence.push(diff * i as i32);
        }
    }

    fn generate_geometric(&mut self, ratio: i32) {
        for i in 0..self.size {
            self.sequence.push(ratio.pow(i as u32));
        }
    }
}

struct DataProcessor {
    sequence: Vec<i32>,
}

impl DataProcessor {
    fn new(sequence: Vec<i32>) -> Self {
        DataProcessor { sequence }
    }

    fn calculate_mean(&self) -> f64 {
        self.sequence.iter().sum::<i32>() as f64 / self.sequence.len() as f64
    }

    fn calculate_median(&self) -> f64 {
        let mut sorted_seq = self.sequence.clone();
        sorted_seq.sort_unstable();
        let mid = sorted_seq.len() / 2;
        if sorted_seq.len() % 2 == 0 {
            (sorted_seq[mid - 1] as f64 + sorted_seq[mid] as f64) / 2.0
        } else {
            sorted_seq[mid] as f64
        }
    }

    fn calculate_variance(&self) -> f64 {
        let mean = self.calculate_mean();
        self.sequence.iter().map(|&x| (x as f64 - mean).powi(2)).sum::<f64>() / self.sequence.len() as f64
    }
}

struct Optimizer {
    processor: DataProcessor,
}

impl Optimizer {
    fn new(processor: DataProcessor) -> Self {
        Optimizer { processor }
    }

    fn optimize_supply_chain(&self) -> std::collections::HashMap<&'static str, f64> {
        let mean = self.processor.calculate_mean();
        let median = self.processor.calculate_median();
        let variance = self.processor.calculate_variance();
        let mut result = std::collections::HashMap::new();
        result.insert("mean", mean);
        result.insert("median", median);
        result.insert("variance", variance);
        result
    }
}

fn main() {
    let size = 10;
    let diff = 2;
    let ratio = 3;
    let mut generator = SequenceGenerator::new(size);
    generator.generate_fibonacci();
    let processor = DataProcessor::new(generator.sequence);
    let optimizer = Optimizer::new(processor);
    let result = optimizer.optimize_supply_chain();
    println!("{:?}", result);
}