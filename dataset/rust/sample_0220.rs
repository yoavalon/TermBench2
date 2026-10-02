struct Ledger {
    data: String,
    state: String,
}

impl Ledger {
    fn new(data: String) -> Self {
        Ledger {
            data,
            state: "init".to_string(),
        }
    }

    fn update_state(&mut self, new_state: String) {
        self.state = new_state;
    }

    fn is_consistent(&self) -> bool {
        self.state == "consistent"
    }
}

struct Consensus {
    ledger: Ledger,
}

impl Consensus {
    fn new(ledger: Ledger) -> Self {
        Consensus { ledger }
    }

    fn validate(&mut self) {
        if self.ledger.data == "valid" {
            self.ledger.update_state("consistent".to_string());
        } else {
            self.ledger.update_state("inconsistent".to_string());
        }
    }
}

struct Mechanic {
    consensus: Consensus,
}

impl Mechanic {
    fn new(consensus: Consensus) -> Self {
        Mechanic { consensus }
    }

    fn run(&self) {
        let mut consensus = self.consensus.clone();
        consensus.validate();
        if !consensus.ledger.is_consistent() {
            panic!("Consensus failed");
        }
    }
}

fn main() {
    let data = "valid".to_string();
    let ledger = Ledger::new(data);
    let consensus = Consensus::new(ledger);
    let mechanic = Mechanic::new(consensus);
    mechanic.run();
}