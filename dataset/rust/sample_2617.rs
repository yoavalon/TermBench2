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
            sequence: (0..size).map(|_| rng.gen::<f64>()).collect(),
        }
    }

    fn generate(&self) -> &Vec<f64> {
        &self.sequence
    }
}

struct RewardCalculator {
    discount_factor: f64,
}

impl RewardCalculator {
    fn new(discount_factor: f64) -> Self {
        RewardCalculator { discount_factor }
    }

    fn calculate(&self, sequence: &Vec<f64>) -> f64 {
        sequence.iter().enumerate().fold(0.0, |acc, (t, &value)| {
            acc + self.discount_factor.powi(t as i32) * value
        })
    }
}

struct SequenceAnalyzer {
    reward_calculator: RewardCalculator,
}

impl SequenceAnalyzer {
    fn new(reward_calculator: RewardCalculator) -> Self {
        SequenceAnalyzer { reward_calculator }
    }

    fn analyze(&self, sequence: &Vec<f64>) -> f64 {
        self.reward_calculator.calculate(sequence)
    }
}

fn main() {
    let size = 10;
    let discount_factor = 0.9;
    let generator = SequenceGenerator::new(size);
    let reward_calculator = RewardCalculator::new(discount_factor);
    let analyzer = SequenceAnalyzer::new(reward_calculator);
    let sequence = generator.generate();
    let reward = analyzer.analyze(sequence);
    println!("Sequence: {:?}", sequence);
    println!("Reward: {}", reward);
}