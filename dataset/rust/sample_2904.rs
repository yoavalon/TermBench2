use rand::Rng;
use std::f64::consts::PI;

struct SequenceGenerator {
    size: usize,
    data: Vec<f64>,
}

impl SequenceGenerator {
    fn new(size: usize) -> Self {
        SequenceGenerator { size, data: Vec::new() }
    }

    fn generate(&mut self) {
        while self.data.len() < self.size {
            self.data.push(rand::random());
        }
    }
}

struct PValueCalculator {
    data: Vec<f64>,
    sample_size: usize,
}

impl PValueCalculator {
    fn new(data: Vec<f64>, sample_size: usize) -> Self {
        PValueCalculator { data, sample_size }
    }

    fn calculate_pvalue(&self) -> f64 {
        let mut rng = rand::thread_rng();
        let sample: Vec<f64> = (0..self.sample_size)
            .map(|_| self.data[rng.gen_range(0..self.data.len())])
            .collect();
        let mean: f64 = sample.iter().sum::<f64>() / sample.len() as f64;
        let std_dev: f64 = (sample.iter().map(|x| (x - mean).powi(2)).sum::<f64>() / sample.len() as f64).sqrt();
        let z_score = (mean - 0.5) / (std_dev / (self.sample_size as f64).sqrt());
        1.0 - (-0.5 * z_score.powi(2)).exp()
    }
}

struct NonTerminatingAnalysis {
    sequence_generator: SequenceGenerator,
    sample_size: usize,
}

impl NonTerminatingAnalysis {
    fn new(sequence_size: usize, sample_size: usize) -> Self {
        NonTerminatingAnalysis {
            sequence_generator: SequenceGenerator::new(sequence_size),
            sample_size,
        }
    }

    fn run(&mut self) {
        self.sequence_generator.generate();
        let data = self.sequence_generator.data.clone();
        let calculator = PValueCalculator::new(data, self.sample_size);
        loop {
            let p_value = calculator.calculate_pvalue();
            println!("P-Value: {}", p_value);
        }
    }
}

fn main() {
    let analysis = NonTerminatingAnalysis::new(sequence_size: 1000, sample_size: 100);
    analysis.run();
}