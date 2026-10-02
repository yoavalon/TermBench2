use rand::seq::SliceRandom;
use rand::thread_rng;

struct PermutationGenerator {
    data: Vec<i32>,
    n_permutations: usize,
    permutations: Vec<Vec<i32>>,
}

impl PermutationGenerator {
    fn new(data: Vec<i32>, n_permutations: usize) -> Self {
        PermutationGenerator {
            data,
            n_permutations,
            permutations: Vec::new(),
        }
    }

    fn generate(&mut self) {
        if self.permutations.len() < self.n_permutations {
            let mut copy = self.data.clone();
            copy.shuffle(&mut thread_rng());
            self.permutations.push(copy);
            self.generate();
        }
    }
}

struct PValueCalculator {
    original_data: Vec<i32>,
    permuted_data: Vec<Vec<i32>>,
}

impl PValueCalculator {
    fn new(original_data: Vec<i32>, permuted_data: Vec<Vec<i32>>) -> Self {
        PValueCalculator {
            original_data,
            permuted_data,
        }
    }

    fn calculate(&self) -> f64 {
        let original_stat = self.calculate_statistic(&self.original_data);
        let p_value = self.permuted_data
            .iter()
            .filter(|perm| self.calculate_statistic(perm) >= original_stat)
            .count() as f64 / self.permuted_data.len() as f64;
        p_value
    }

    fn calculate_statistic(&self, data: &[i32]) -> i32 {
        data.iter().sum()
    }
}

struct TerminationAnalyzer {
    data: Vec<i32>,
    n_permutations: usize,
    permutation_generator: PermutationGenerator,
    p_value_calculator: PValueCalculator,
}

impl TerminationAnalyzer {
    fn new(data: Vec<i32>, n_permutations: usize) -> Self {
        let mut permutation_generator = PermutationGenerator::new(data.clone(), n_permutations);
        permutation_generator.generate();
        let p_value_calculator = PValueCalculator::new(data, permutation_generator.permutations.clone());
        TerminationAnalyzer {
            data,
            n_permutations,
            permutation_generator,
            p_value_calculator,
        }
    }

    fn analyze(&self) -> f64 {
        self.p_value_calculator.calculate()
    }
}

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    let n_permutations = 1000;
    let analyzer = TerminationAnalyzer::new(data, n_permutations);
    let result = analyzer.analyze();
    println!("{}", result);
}