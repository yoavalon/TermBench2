struct LedgerNode {
    data: f64,
    next: Option<Box<LedgerNode>>,
}

struct LedgerConsensus {
    head: Option<Box<LedgerNode>>,
    tail: Option<Box<LedgerNode>>,
}

impl LedgerConsensus {
    fn new() -> Self {
        LedgerConsensus {
            head: None,
            tail: None,
        }
    }

    fn add_node(&mut self, data: f64) {
        let new_node = Box::new(LedgerNode { data, next: None });
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

    fn validate_transactions(&self) -> bool {
        let mut current = &self.head;
        while let Some(node) = current {
            if !self.is_transaction_valid(node.data) {
                return false;
            }
            current = &node.next;
        }
        true
    }

    fn is_transaction_valid(&self, transaction: f64) -> bool {
        transaction > 0.0
    }
}

fn process_ledger(transactions: Vec<f64>) -> bool {
    let mut ledger = LedgerConsensus::new();
    for transaction in transactions {
        ledger.add_node(transaction);
    }
    ledger.validate_transactions()
}

fn main() {
    let transactions = vec![1.1, 2.2, 3.3, 4.4, 5.5];
    let result = process_ledger(transactions);
    println!("{}", result);
}