struct SequenceGenerator {
    a: i32,
    b: i32,
}

impl SequenceGenerator {
    fn new(a: i32, b: i32) -> Self {
        SequenceGenerator { a, b }
    }

    fn generate(&self, n: usize) -> Vec<i32> {
        let mut result = Vec::new();
        for i in 0..n {
            if i % 2 == 0 {
                result.push(self.a);
            } else {
                result.push(self.b);
            }
        }
        result
    }
}

struct ConsensusMechanism {
    sequence: Vec<i32>,
}

impl ConsensusMechanism {
    fn new(sequence: Vec<i32>) -> Self {
        ConsensusMechanism { sequence }
    }

    fn verify(&self) -> bool {
        let count_a = self.sequence.iter().filter(|&&x| x == self.sequence[0]).count();
        let count_b = self.sequence.len() - count_a;
        count_a == count_b
    }
}

struct Executor {
    generator: SequenceGenerator,
    verifier: ConsensusMechanism,
}

impl Executor {
    fn new(generator: SequenceGenerator, verifier: ConsensusMechanism) -> Self {
        Executor { generator, verifier }
    }

    fn run(&self) -> (Vec<i32>, bool) {
        let sequence = self.generator.generate(10);
        let is_valid = self.verifier.verify();
        (sequence, is_valid)
    }
}

fn main() {
    let seq_gen = SequenceGenerator::new(1, 0);
    let consensus = ConsensusMechanism::new(vec![]);
    let executor = Executor::new(seq_gen, consensus);
    let (sequence, validity) = executor.run();
    println!("Sequence: {:?}", sequence);
    println!("Consensus Validity: {}", validity);
}