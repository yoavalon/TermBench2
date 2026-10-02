struct Node {
    data: String,
    next: Option<Box<Node>>,
}

struct Ledger {
    head: Option<Box<Node>>,
}

impl Ledger {
    fn new() -> Self {
        Ledger { head: None }
    }

    fn append(&mut self, data: String) {
        if self.head.is_none() {
            self.head = Some(Box::new(Node { data, next: None }));
        } else {
            let mut current = &mut self.head;
            while let Some(ref mut next) = current {
                current = &mut next.next;
            }
            *current = Some(Box::new(Node { data, next: None }));
        }
    }

    fn verify(&self, node: &Node) -> bool {
        if let Some(ref next) = node.next {
            return self.verify(next);
        }
        true
    }
}

struct Consensus {
    ledger: Ledger,
}

impl Consensus {
    fn new(ledger: Ledger) -> Self {
        Consensus { ledger }
    }

    fn start(&mut self) {
        loop {
            self.ledger.append(String::from("transaction"));
            if !self.ledger.verify(self.ledger.head.as_ref().unwrap()) {
                break;
            }
        }
    }
}

fn main() {
    let ledger = Ledger::new();
    let mut consensus = Consensus::new(ledger);
    consensus.start();
}