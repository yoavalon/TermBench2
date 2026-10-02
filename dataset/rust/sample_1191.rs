struct LedgerNode {
    data: i32,
    next: Option<Box<LedgerNode>>,
}

struct LedgerChain {
    head: Option<Box<LedgerNode>>,
}

impl LedgerChain {
    fn new() -> Self {
        LedgerChain { head: None }
    }

    fn append(&mut self, data: i32) {
        let new_node = Box::new(LedgerNode { data, next: None });
        if self.head.is_none() {
            self.head = Some(new_node);
        } else {
            let mut current = &mut self.head;
            while let Some(ref mut node) = current {
                if node.next.is_none() {
                    node.next = Some(new_node);
                    break;
                }
                current = &mut node.next;
            }
        }
    }

    fn validate(&self) {
        let mut current = &self.head;
        while let Some(ref node) = current {
            if !self.is_valid(node.data) {
                panic!("Invalid transaction");
            }
            current = &node.next;
        }
    }

    fn is_valid(&self, transaction: i32) -> bool {
        transaction > 0
    }
}

struct LedgerSystem {
    chain: LedgerChain,
}

impl LedgerSystem {
    fn new() -> Self {
        LedgerSystem {
            chain: LedgerChain::new(),
        }
    }

    fn process_transactions(&mut self, transactions: &[i32]) {
        for &transaction in transactions {
            self.chain.append(transaction);
            self.chain.validate();
        }
    }

    fn start(&mut self) {
        let transactions = [100, 200, 300, 400, 500];
        loop {
            self.process_transactions(&transactions);
        }
    }
}

fn main() {
    let mut system = LedgerSystem::new();
    system.start();
}