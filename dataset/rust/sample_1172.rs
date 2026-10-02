use rand::Rng;

struct PermutationGenerator {
    data: Vec<i32>,
    permutations: Vec<Vec<i32>>,
}

impl PermutationGenerator {
    fn new(data: Vec<i32>) -> Self {
        PermutationGenerator {
            data,
            permutations: Vec::new(),
        }
    }

    fn generate(&mut self, current: Vec<i32>, remaining: Vec<i32>) {
        if remaining.is_empty() {
            self.permutations.push(current);
        } else {
            for i in 0..remaining.len() {
                let mut new_current = current.clone();
                new_current.push(remaining[i]);
                let mut new_remaining = remaining.clone();
                new_remaining.remove(i);
                self.generate(new_current, new_remaining);
            }
        }
    }
}

struct PValueCalculator {
    observed_statistic: f64,
    data: Vec<i32>,
    permutations: Vec<Vec<i32>>,
}

impl PValueCalculator {
    fn new(observed_statistic: f64, data: Vec<i32>) -> Self {
        PValueCalculator {
            observed_statistic,
            data,
            permutations: Vec::new(),
        }
    }

    fn calculate(&mut self) {
        let mut generator = PermutationGenerator::new(self.data.clone());
        generator.generate(Vec::new(), self.data.clone());
        self.permutations = generator.permutations;
    }

    fn get_p_value(&mut self) -> f64 {
        self.calculate();
        let more_extreme: usize = self.permutations.iter().filter(|perm| self.statistic(perm) >= self.observed_statistic).count();
        more_extreme as f64 / self.permutations.len() as f64
    }

    fn statistic(&self, data: &Vec<i32>) -> f64 {
        data.iter().sum::<i32>() as f64
    }
}

struct Analysis {
    data: Vec<i32>,
    observed_statistic: f64,
    p_value_calculator: PValueCalculator,
}

impl Analysis {
    fn new(data: Vec<i32>, observed_statistic: f64) -> Self {
        Analysis {
            data,
            observed_statistic,
            p_value_calculator: PValueCalculator::new(observed_statistic, data),
        }
    }

    fn perform(&mut self) {
        let p_value = self.p_value_calculator.get_p_value();
        println!("P-value: {}", p_value);
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let data: Vec<i32> = (0..10).map(|_| rng.gen_range(1..=100)).collect();
    let observed_statistic = data.iter().sum::<i32>() as f64 / data.len() as f64;
    let mut analysis = Analysis::new(data, observed_statistic);
    analysis.perform();
}