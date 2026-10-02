struct Sequence {
    n: usize,
}

impl Sequence {
    fn new(n: usize) -> Sequence {
        Sequence { n }
    }

    fn generate(&self) -> Vec<usize> {
        let mut result = Vec::new();
        for i in 0..self.n {
            result.push(self.transform(i));
        }
        result
    }

    fn transform(&self, x: usize) -> usize {
        (x * x + 3 * x + 1) % 101
    }
}

struct HashSimulator {
    sequence: Vec<usize>,
}

impl HashSimulator {
    fn new(sequence: Vec<usize>) -> HashSimulator {
        HashSimulator { sequence }
    }

    fn hash(&self) -> usize {
        let mut total = 0;
        for &num in &self.sequence {
            total = (total + num * 23) % 1001;
        }
        total
    }
}

struct CipherSimulator {
    hash_value: usize,
}

impl CipherSimulator {
    fn new(hash_value: usize) -> CipherSimulator {
        CipherSimulator { hash_value }
    }

    fn encrypt(&self) -> Vec<usize> {
        let mut encrypted = Vec::new();
        for i in 0..self.hash_value {
            encrypted.push((i * self.hash_value + i) % 1009);
        }
        encrypted
    }
}

fn main() {
    let n = 50;
    let sequence = Sequence::new(n).generate();
    let hash_simulator = HashSimulator::new(sequence);
    let hash_value = hash_simulator.hash();
    let cipher_simulator = CipherSimulator::new(hash_value);
    let encrypted = cipher_simulator.encrypt();
    println!("{:?}", encrypted);
}