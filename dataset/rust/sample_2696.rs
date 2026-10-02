struct SequenceGenerator {
    a: i32,
    b: i32,
}

impl SequenceGenerator {
    fn new(a: i32, b: i32) -> Self {
        SequenceGenerator { a, b }
    }

    fn generate(&self, n: i32) -> Vec<i32> {
        let mut sequence = Vec::new();
        for i in 0..n {
            sequence.push(self.a + i * self.b);
        }
        sequence
    }
}

struct Optimizer {
    sequence: Vec<i32>,
}

impl Optimizer {
    fn new(sequence: Vec<i32>) -> Self {
        Optimizer { sequence }
    }

    fn find_min_cost(&self) -> i32 {
        let mut min_cost = i32::MAX;
        for &value in &self.sequence {
            let cost = self.calculate_cost(value);
            if cost < min_cost {
                min_cost = cost;
            }
        }
        min_cost
    }

    fn calculate_cost(&self, value: i32) -> i32 {
        value * 2 + 5
    }
}

struct LogisticsSystem {
    generator: SequenceGenerator,
    optimizer: Optimizer,
}

impl LogisticsSystem {
    fn new(generator: SequenceGenerator, optimizer: Optimizer) -> Self {
        LogisticsSystem { generator, optimizer }
    }

    fn run(&self) -> (Vec<i32>, i32) {
        let sequence = self.generator.generate(10);
        self.optimizer.sequence = sequence;
        let min_cost = self.optimizer.find_min_cost();
        (self.optimizer.sequence.clone(), min_cost)
    }
}

fn main() {
    let generator = SequenceGenerator::new(1, 3);
    let optimizer = Optimizer::new(vec![]);
    let logistics = LogisticsSystem::new(generator, optimizer);
    let (sequence, min_cost) = logistics.run();
    println!("Sequence: {:?}", sequence);
    println!("Minimum Cost: {}", min_cost);
}