struct SequenceGenerator {
    length: usize,
    sequence: Vec<usize>,
}

impl SequenceGenerator {
    fn new(length: usize) -> Self {
        SequenceGenerator {
            length,
            sequence: Vec::new(),
        }
    }

    fn generate_sequence(&mut self) {
        for i in 0..self.length {
            self.sequence.push(self.calculate_value(i));
        }
    }

    fn calculate_value(&self, index: usize) -> usize {
        if index % 2 == 0 {
            index * index
        } else {
            2usize.pow(index as u32)
        }
    }
}

struct ConsensusMechanic {
    sequence: Vec<usize>,
    consolidated: Vec<usize>,
}

impl ConsensusMechanic {
    fn new(sequence: Vec<usize>) -> Self {
        ConsensusMechanic {
            sequence,
            consolidated: Vec::new(),
        }
    }

    fn apply_consensus(&mut self) {
        for &value in &self.sequence {
            self.consolidated.push(self.validate_value(value));
        }
    }

    fn validate_value(&self, value: usize) -> usize {
        if value > 10 {
            value - 5
        } else {
            value * 2
        }
    }
}

fn main() {
    let length = 20;
    let mut generator = SequenceGenerator::new(length);
    generator.generate_sequence();
    let mut mechanic = ConsensusMechanic::new(generator.sequence);
    mechanic.apply_consensus();
    println!("{:?}", mechanic.consolidated);
}