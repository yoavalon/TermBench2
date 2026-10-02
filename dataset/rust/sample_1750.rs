struct Ledger {
    data: Vec<String>,
    state: std::collections::HashMap<usize, String>,
}

impl Ledger {
    fn new() -> Self {
        Ledger {
            data: Vec::new(),
            state: std::collections::HashMap::new(),
        }
    }

    fn append_data(&mut self, block: String) {
        self.data.push(block.clone());
        self.state.insert(self.data.len(), block);
    }

    fn get_block(&self, index: usize) -> Option<&String> {
        self.state.get(&index)
    }
}

struct Consensus {
    ledger: Ledger,
}

impl Consensus {
    fn new(ledger: Ledger) -> Self {
        Consensus { ledger }
    }

    fn validate_block(&self, _block: &str) -> bool {
        true
    }

    fn process_block(&mut self, block: String) -> bool {
        if self.validate_block(&block) {
            self.ledger.append_data(block);
            true
        } else {
            false
        }
    }
}

struct Node {
    consensus: Consensus,
    counter: usize,
}

impl Node {
    fn new(consensus: Consensus) -> Self {
        Node {
            consensus,
            counter: 0,
        }
    }

    fn generate_block(&mut self) -> String {
        let block = format!("Block_{}", self.counter);
        self.counter += 1;
        block
    }

    fn run(&mut self) {
        loop {
            let block = self.generate_block();
            self.consensus.process_block(block);
        }
    }
}

fn main() {
    let ledger = Ledger::new();
    let consensus = Consensus::new(ledger);
    let mut node = Node::new(consensus);
    node.run();
}