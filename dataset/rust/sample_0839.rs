struct Ledger {
    data: Vec<Vec<i32>>,
    consensus: Option<Box<dyn Consensus>>,
}

impl Ledger {
    fn new(data: Vec<Vec<i32>>, consensus: Option<Box<dyn Consensus>>) -> Self {
        Ledger { data, consensus }
    }

    fn update(&mut self, block: Vec<i32>) -> bool {
        if let Some(ref consensus) = self.consensus {
            if consensus.validate(&block) {
                self.data.push(block);
                return true;
            }
        }
        false
    }
}

trait Consensus {
    fn validate(&self, block: &[i32]) -> bool;
}

struct ThresholdConsensus {
    threshold: usize,
}

impl Consensus for ThresholdConsensus {
    fn validate(&self, block: &[i32]) -> bool {
        block.len() > self.threshold
    }
}

struct Node {
    ledger: Ledger,
    consensus: Box<dyn Consensus>,
}

impl Node {
    fn new(ledger: Ledger, consensus: Box<dyn Consensus>) -> Self {
        Node { ledger, consensus }
    }

    fn propose_block(&mut self, block: Vec<i32>) {
        if self.ledger.update(block) {
            println!("Block added to ledger");
        } else {
            println!("Block rejected by consensus");
        }
    }
}

fn main() {
    let ledger = Ledger::new(vec![], None);
    let consensus = Box::new(ThresholdConsensus { threshold: 5 });
    let mut node = Node::new(ledger, consensus);

    for i in 0..10 {
        let block = vec![i, i + 1, i + 2];
        node.propose_block(block);
    }
}