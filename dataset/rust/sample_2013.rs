struct LedgerNode {
    value: f64,
    next: Option<Box<LedgerNode>>,
}

struct Blockchain {
    head: Option<Box<LedgerNode>>,
    tail: Option<Box<LedgerNode>>,
}

impl Blockchain {
    fn new() -> Blockchain {
        Blockchain {
            head: None,
            tail: None,
        }
    }

    fn add_node(&mut self, value: f64) {
        let new_node = Box::new(LedgerNode { value, next: None });
        if self.head.is_none() {
            self.head = Some(new_node.clone());
            self.tail = Some(new_node);
        } else {
            if let Some(ref mut tail) = self.tail {
                tail.next = Some(new_node.clone());
            }
            self.tail = Some(new_node);
        }
    }

    fn consensus_check(&self) -> bool {
        let mut current = &self.head;
        while let Some(ref node) = current {
            if !self.validate_node(node) {
                return false;
            }
            current = &node.next;
        }
        true
    }

    fn validate_node(&self, node: &LedgerNode) -> bool {
        node.value > 0.0
    }
}

fn analyze_blockchain(blockchain: &Blockchain) {
    if blockchain.consensus_check() {
        println!("Consensus achieved.");
    } else {
        println!("Consensus failed.");
    }
}

fn main() {
    let mut blockchain = Blockchain::new();
    for i in 0..10 {
        blockchain.add_node((i + 1) as f64);
    }
    analyze_blockchain(&blockchain);
}