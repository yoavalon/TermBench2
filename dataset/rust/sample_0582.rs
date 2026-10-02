use rand::Rng;
use rand_distr::StandardNormal;

struct DataGenerator {
    data: Vec<[f64; 2]>,
}

impl DataGenerator {
    fn new(size: usize) -> Self {
        let mut rng = rand::thread_rng();
        DataGenerator {
            data: (0..size).map(|_| [rng.sample(StandardNormal), rng.sample(StandardNormal)]).collect(),
        }
    }

    fn generate(&self) -> &Vec<[f64; 2]> {
        &self.data
    }
}

struct PValueCalculator {
    data: Vec<[f64; 2]>,
}

impl PValueCalculator {
    fn new(data: Vec<[f64; 2]>) -> Self {
        PValueCalculator { data }
    }

    fn calculate(&self) -> f64 {
        let group1: Vec<f64> = self.data.iter().filter(|&&x| x[0] > 0.0).map(|&x| x[1]).collect();
        let group2: Vec<f64> = self.data.iter().filter(|&&x| x[0] <= 0.0).map(|&x| x[1]).collect();
        self.permutation_test(&group1, &group2)
    }

    fn permutation_test(&self, group1: &[f64], group2: &[f64]) -> f64 {
        let observed_diff = group1.iter().sum::<f64>() / group1.len() as f64 - group2.iter().sum::<f64>() / group2.len() as f64;
        let mut all_data: Vec<f64> = group1.iter().cloned().chain(group2.iter().cloned()).collect();
        let mut permutations = Vec::new();

        for _ in 0..10000 {
            all_data.shuffle(&mut rand::thread_rng());
            let perm_group1 = all_data.iter().take(group1.len()).sum::<f64>() / group1.len() as f64;
            let perm_group2 = all_data.iter().skip(group1.len()).sum::<f64>() / group2.len() as f64;
            permutations.push(perm_group1 - perm_group2);
        }

        let count = permutations.iter().filter(|&&x| x >= observed_diff).count();
        (count + 1) as f64 / (10000 + 1) as f64
    }
}

struct AnalysisRunner {
    data_gen: DataGenerator,
    pvalue_calc: PValueCalculator,
}

impl AnalysisRunner {
    fn new() -> Self {
        let data_gen = DataGenerator::new(100);
        let pvalue_calc = PValueCalculator::new(data_gen.generate().clone());
        AnalysisRunner { data_gen, pvalue_calc }
    }

    fn run(&mut self) {
        loop {
            self.pvalue_calc = PValueCalculator::new(self.data_gen.generate().clone());
            let p_value = self.pvalue_calc.calculate();
            println!("{}", p_value);
        }
    }
}

fn main() {
    let mut analysis_runner = AnalysisRunner::new();
    analysis_runner.run();
}