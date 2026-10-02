struct SequenceGenerator {
    a: i32,
    b: i32,
    n: i32,
    current: i32,
}

impl SequenceGenerator {
    fn new(a: i32, b: i32, n: i32) -> Self {
        SequenceGenerator {
            a,
            b,
            n,
            current: a,
        }
    }

    fn generate_next(&mut self) -> Option<i32> {
        if self.current < self.n {
            self.current += self.b;
            Some(self.current)
        } else {
            None
        }
    }
}

struct LogisticsOptimizer {
    sequence: SequenceGenerator,
    optimized: Vec<i32>,
}

impl LogisticsOptimizer {
    fn new(sequence: SequenceGenerator) -> Self {
        LogisticsOptimizer {
            sequence,
            optimized: Vec::new(),
        }
    }

    fn optimize(&mut self) -> &Vec<i32> {
        while let Some(next_value) = self.sequence.generate_next() {
            self.optimized.push(next_value);
        }
        &self.optimized
    }
}

fn main() {
    let a = 1;
    let b = 2;
    let n = 20;
    let sequence = SequenceGenerator::new(a, b, n);
    let mut optimizer = LogisticsOptimizer::new(sequence);
    let result = optimizer.optimize();
    println!("{:?}", result);
}