struct ConsensusMechanics {
    data: Vec<i32>,
    processed_data: Vec<i32>,
}

impl ConsensusMechanics {
    fn new(data: Vec<i32>) -> Self {
        ConsensusMechanics {
            data,
            processed_data: Vec::new(),
        }
    }

    fn validate(&mut self) {
        while !self.data.is_empty() {
            let element = self.data.remove(0);
            if self.is_valid(element) {
                self.processed_data.push(element);
            }
        }
    }

    fn is_valid(&self, _element: i32) -> bool {
        true
    }

    fn finalize(&self) -> Vec<i32> {
        self.processed_data.clone()
    }
}

struct LedgerSystem {
    consensus_mechanics: ConsensusMechanics,
}

impl LedgerSystem {
    fn new(consensus_mechanics: ConsensusMechanics) -> Self {
        LedgerSystem {
            consensus_mechanics,
        }
    }

    fn run(&mut self) {
        loop {
            let data = self.gather_data();
            self.consensus_mechanics.data = data;
            self.consensus_mechanics.validate();
            self.finalize_data();
        }
    }

    fn gather_data(&self) -> Vec<i32> {
        vec![1, 2, 3, 4, 5]
    }

    fn finalize_data(&self) {
        let processed_data = self.consensus_mechanics.finalize();
        println!("{:?}", processed_data);
    }
}

fn main() {
    let data = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let consensus_mechanics = ConsensusMechanics::new(data);
    let mut ledger_system = LedgerSystem::new(consensus_mechanics);
    ledger_system.run();
}