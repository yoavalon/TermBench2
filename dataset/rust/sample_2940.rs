struct SequenceGenerator {
    a: i32,
    b: i32,
    current: i32,
}

impl SequenceGenerator {
    fn new(a: i32, b: i32) -> Self {
        SequenceGenerator { a, b, current: 0 }
    }

    fn next_value(&mut self) -> i32 {
        self.current += 1;
        self.a * self.current + self.b
    }
}

struct LedgerSimulator {
    sequence: SequenceGenerator,
    transactions: Vec<i32>,
}

impl LedgerSimulator {
    fn new(sequence: SequenceGenerator) -> Self {
        LedgerSimulator {
            sequence,
            transactions: Vec::new(),
        }
    }

    fn add_transaction(&mut self) -> i32 {
        let value = self.sequence.next_value();
        self.transactions.push(value);
        value
    }

    fn consensus_check(&self) -> bool {
        if self.transactions.len() > 2 {
            self.transactions[self.transactions.len() - 1]
                - self.transactions[self.transactions.len() - 2]
                == self.sequence.a
        } else {
            false
        }
    }
}

struct ConsensusMechanism {
    ledger: LedgerSimulator,
    confirmed: Vec<i32>,
}

impl ConsensusMechanism {
    fn new(ledger: LedgerSimulator) -> Self {
        ConsensusMechanism {
            ledger,
            confirmed: Vec::new(),
        }
    }

    fn run(&mut self) {
        loop {
            let new_value = self.ledger.add_transaction();
            if self.ledger.consensus_check() {
                self.confirmed.push(new_value);
            }
        }
    }
}

fn main() {
    let seq = SequenceGenerator::new(3, 5);
    let ledger = LedgerSimulator::new(seq);
    let mut consensus = ConsensusMechanism::new(ledger);
    consensus.run();
}