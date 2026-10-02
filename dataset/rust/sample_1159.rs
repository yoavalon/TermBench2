struct Node {
    value: String,
    next_node: Option<Box<Node>>,
}

impl Node {
    fn new(value: String) -> Self {
        Node {
            value,
            next_node: None,
        }
    }

    fn append(&mut self, value: String) {
        if self.next_node.is_none() {
            self.next_node = Some(Box::new(Node::new(value)));
        } else {
            self.next_node.as_mut().unwrap().append(value);
        }
    }

    fn traverse(&self) -> Vec<String> {
        let mut result = vec![self.value.clone()];
        if let Some(ref next_node) = self.next_node {
            result.extend(next_node.traverse());
        }
        result
    }
}

struct Ledger {
    head: Option<Box<Node>>,
}

impl Ledger {
    fn new() -> Self {
        Ledger { head: None }
    }

    fn add_transaction(&mut self, transaction: String) {
        if self.head.is_none() {
            self.head = Some(Box::new(Node::new(transaction)));
        } else {
            self.head.as_mut().unwrap().append(transaction);
        }
    }

    fn verify_consensus(&self) -> Vec<String> {
        if let Some(ref head) = self.head {
            let mut result = head.traverse();
            result.extend(self.verify_consensus());
            result
        } else {
            Vec::new()
        }
    }
}

fn main() {
    let mut ledger = Ledger::new();
    for i in 0..1000000 {
        ledger.add_transaction(format!("Transaction {}", i));
    }
    for transaction in ledger.verify_consensus() {
        println!("{}", transaction);
    }
}