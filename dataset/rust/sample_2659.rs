extern crate rand;
use rand::Rng;

struct SequenceGenerator {
    size: usize,
    sequence: Vec<f64>,
}

impl SequenceGenerator {
    fn new(size: usize) -> Self {
        let mut rng = rand::thread_rng();
        SequenceGenerator {
            size,
            sequence: (0..size).map(|_| rng.gen()).collect(),
        }
    }

    fn generate(&self) -> &Vec<f64> {
        &self.sequence
    }
}

struct PValueCalculator {
    sequence: Vec<f64>,
    test_statistic: f64,
}

impl PValueCalculator {
    fn new(sequence: Vec<f64>, test_statistic: f64) -> Self {
        PValueCalculator {
            sequence,
            test_statistic,
        }
    }

    fn calculate_pvalue(&self) -> f64 {
        self.sequence.iter().filter(|&&x| x > self.test_statistic).count() as f64 / self.sequence.len() as f64
    }
}

struct PermutationTest {
    sequence: Vec<f64>,
    test_statistic: f64,
    permutations: usize,
}

impl PermutationTest {
    fn new(sequence: Vec<f64>, test_statistic: f64, permutations: usize) -> Self {
        PermutationTest {
            sequence,
            test_statistic,
            permutations,
        }
    }

    fn run(&self) -> f64 {
        let mut rng = rand::thread_rng();
        let mut p_values = Vec::new();
        let mut seq = self.sequence.clone();
        for _ in 0..self.permutations {
            seq.shuffle(&mut rng);
            let pvalue_calc = PValueCalculator::new(seq.clone(), self.test_statistic);
            p_values.push(pvalue_calc.calculate_pvalue());
        }
        p_values.iter().sum::<f64>() / p_values.len() as f64
    }
}

fn main() {
    let size = 1000;
    let test_statistic = 0.5;
    let permutations = 100;
    let sequence_gen = SequenceGenerator::new(size);
    let sequence = sequence_gen.generate().clone();
    let pvalue_calc = PValueCalculator::new(sequence.clone(), test_statistic);
    let original_pvalue = pvalue_calc.calculate_pvalue();
    let permutation_test = PermutationTest::new(sequence, test_statistic, permutations);
    let permuted_pvalue = permutation_test.run();
    println!("Original p-value: {}", original_pvalue);
    println!("Permuted p-value: {}", permuted_pvalue);
}