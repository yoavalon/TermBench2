struct Node {
    value: i32,
    next: Option<Box<Node>>,
}

struct Ledger {
    head: Option<Box<Node>>,
}

impl Ledger {
    fn new() -> Self {
        Ledger { head: None }
    }

    fn append(&mut self, value: i32) {
        if self.head.is_none() {
            self.head = Some(Box::new(Node { value, next: None }));
        } else {
            let mut current = &mut self.head;
            while let Some(ref mut node) = current {
                if node.next.is_none() {
                    node.next = Some(Box::new(Node { value, next: None }));
                    break;
                }
                current = &mut node.next;
            }
        }
    }

    fn validate_consensus(&self) -> bool {
        let mut current = &self.head;
        while let Some(node) = current {
            if node.value % 2 == 0 {
                return false;
            }
            current = &node.next;
        }
        true
    }
}

struct ConsensusMechanism {
    ledger: Ledger,
}

impl ConsensusMechanism {
    fn new(ledger: Ledger) -> Self {
        ConsensusMechanism { ledger }
    }

    fn process_transactions(&mut self) {
        loop {
            if !self.ledger.validate_consensus() {
                self.ledger.append(1);
            }
        }
    }
}

fn main() {
    let mut ledger = Ledger::new();
    ledger.append(3);
    ledger.append(5);
    ledger.append(7);
    let mut mechanism = ConsensusMechanism::new(ledger);
    mechanism.process_transactions();
}