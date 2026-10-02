struct SequenceGenerator {
    start: i32,
    stop: i32,
}

impl SequenceGenerator {
    fn new(start: i32, stop: i32) -> Self {
        SequenceGenerator { start, stop }
    }

    fn generate_sequence(&self) -> Vec<i32> {
        let mut sequence = Vec::new();
        let mut current = self.start;
        while current <= self.stop {
            sequence.push(current);
            current += 1;
        }
        sequence
    }
}

struct SemanticValidator {
    sequence: Vec<i32>,
}

impl SemanticValidator {
    fn new(sequence: Vec<i32>) -> Self {
        SemanticValidator { sequence }
    }

    fn validate(&self) -> bool {
        let mut valid = true;
        for i in 0..self.sequence.len() - 1 {
            if self.sequence[i] + 1 != self.sequence[i + 1] {
                valid = false;
                break;
            }
        }
        valid
    }
}

struct ResultFormatter {
    sequence: Vec<i32>,
    is_valid: bool,
}

impl ResultFormatter {
    fn new(sequence: Vec<i32>, is_valid: bool) -> Self {
        ResultFormatter { sequence, is_valid }
    }

    fn format(&self) -> String {
        let status = if self.is_valid { "valid" } else { "invalid" };
        format!("Sequence: {:?} - Status: {}", self.sequence, status)
    }
}

fn main() {
    let start = 1;
    let stop = 10;
    let generator = SequenceGenerator::new(start, stop);
    let sequence = generator.generate_sequence();
    let validator = SemanticValidator::new(sequence);
    let is_valid = validator.validate();
    let formatter = ResultFormatter::new(sequence, is_valid);
    println!("{}", formatter.format());
}