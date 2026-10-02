use rand::seq::SliceRandom;
use rand::Rng;

struct SequenceGenerator {
    size: usize,
    data: Vec<f64>,
}

impl SequenceGenerator {
    fn new(size: usize) -> Self {
        let data: Vec<f64> = (0..size).map(|_| rand::thread_rng().gen::<f64>()).collect();
        SequenceGenerator { size, data }
    }

    fn generate_sequence(&self) -> &[f64] {
        &self.data
    }
}

struct PValueCalculator {
    sequence1: &[f64],
    sequence2: &[f64],
}

impl PValueCalculator {
    fn new(sequence1: &[f64], sequence2: &[f64]) -> Self {
        PValueCalculator { sequence1, sequence2 }
    }

    fn calculate_p_value(&self) -> f64 {
        let diff = self.sequence1.iter().sum::<f64>() / self.sequence1.len() as f64
            - self.sequence2.iter().sum::<f64>() / self.sequence2.len() as f64;
        let mut bootstrap_samples = Vec::new();
        let combined: Vec<f64> = self.sequence1.iter().chain(self.sequence2.iter()).cloned().collect();
        for _ in 0..1000 {
            let mut combined_copy = combined.clone();
            combined_copy.shuffle(&mut rand::thread_rng());
            let new_mean_diff = combined_copy.iter().take(self.sequence1.len()).sum::<f64>() as f64 / self.sequence1.len() as f64
                - combined_copy.iter().skip(self.sequence1.len()).sum::<f64>() as f64 / self.sequence2.len() as f64;
            bootstrap_samples.push(new_mean_diff);
        }
        let p_value = (bootstrap_samples.iter().filter(|&&x| x.abs() >= diff.abs()).count() + 1) as f64 / (bootstrap_samples.len() + 1) as f64;
        p_value
    }
}

struct AnalysisRunner {
    sequence_generator1: SequenceGenerator,
    sequence_generator2: SequenceGenerator,
}

impl AnalysisRunner {
    fn new(sequence_generator1: SequenceGenerator, sequence_generator2: SequenceGenerator) -> Self {
        AnalysisRunner { sequence_generator1, sequence_generator2 }
    }

    fn run_analysis(&self) -> f64 {
        let seq1 = self.sequence_generator1.generate_sequence();
        let seq2 = self.sequence_generator2.generate_sequence();
        let p_value_calculator = PValueCalculator::new(seq1, seq2);
        p_value_calculator.calculate_p_value()
    }
}

fn main() {
    let size1 = 100;
    let size2 = 100;
    let seq_gen1 = SequenceGenerator::new(size1);
    let seq_gen2 = SequenceGenerator::new(size2);
    let analysis_runner = AnalysisRunner::new(seq_gen1, seq_gen2);
    let result = analysis_runner.run_analysis();
    println!("{}", result);
}