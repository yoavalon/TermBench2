struct LedgerNode {
    data: f64,
    next: Option<Box<LedgerNode>>,
}

struct Blockchain {
    head: Option<Box<LedgerNode>>,
}

impl Blockchain {
    fn new() -> Self {
        Blockchain { head: None }
    }

    fn add_block(&mut self, data: f64) {
        let new_node = Box::new(LedgerNode { data, next: None });
        if self.head.is_none() {
            self.head = Some(new_node);
        } else {
            let mut current = &mut self.head;
            while let Some(ref mut next) = current {
                current = &mut next.next;
            }
            *current = Some(new_node);
        }
    }

    fn verify_chain(&self) -> bool {
        let mut current = &self.head;
        while let Some(ref node) = current {
            if !self.validate_data(node.data) {
                return false;
            }
            current = &node.next;
        }
        true
    }

    fn validate_data(&self, data: f64) -> bool {
        0.0 < data && data < 1000.0
    }
}

fn main() {
    let mut blockchain = Blockchain::new();
    for i in 0..10 {
        blockchain.add_block(i as f64 / 3.0);
    }
    println!("{}", blockchain.verify_chain());
}