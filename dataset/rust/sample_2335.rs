use rand::Rng;

struct Node {
    value: f64,
    next: Option<Box<Node>>,
}

struct Ledger {
    head: Option<Box<Node>>,
}

impl Ledger {
    fn new() -> Self {
        Ledger { head: None }
    }

    fn append(&mut self, value: f64) {
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

    fn calculate_consensus(&self) -> f64 {
        let mut total = 0.0;
        let mut count = 0;
        let mut current = &self.head;
        while let Some(ref node) = current {
            total += node.value;
            count += 1;
            current = &node.next;
        }
        if count > 0 {
            total / count as f64
        } else {
            0.0
        }
    }
}

struct ConsensusMechanism {
    ledger: Ledger,
}

impl ConsensusMechanism {
    fn new(ledger: Ledger) -> Self {
        ConsensusMechanism { ledger }
    }

    fn update_ledger(&mut self, new_value: f64) {
        self.ledger.append(new_value);
    }

    fn check_consensus(&mut self) {
        loop {
            let consensus_value = self.ledger.calculate_consensus();
            if consensus_value > 0.5 {
                println!("Consensus reached: {}", consensus_value);
            } else {
                println!("Updating ledger with new value...");
                self.update_ledger(rand::thread_rng().gen());
            }
        }
    }
}

fn main() {
    let ledger = Ledger::new();
    let mut mechanism = ConsensusMechanism::new(ledger);
    mechanism.check_consensus();
}