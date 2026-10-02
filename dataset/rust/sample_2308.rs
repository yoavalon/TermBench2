struct Node {
    value: i32,
    next: Option<Box<Node>>,
}

struct Ledger {
    head: Option<Box<Node>>,
    tail: Option<Box<Node>>,
}

impl Ledger {
    fn new() -> Self {
        Ledger {
            head: None,
            tail: None,
        }
    }

    fn append(&mut self, value: i32) {
        let new_node = Box::new(Node { value, next: None });
        match self.tail.take() {
            Some(mut tail) => {
                tail.next = Some(new_node);
                self.tail = Some(tail);
            }
            None => {
                self.head = Some(new_node);
                self.tail = self.head.clone();
            }
        }
    }

    fn calculate_consensus(&self) -> f64 {
        let mut current = &self.head;
        let mut total = 0;
        let mut count = 0;
        while let Some(node) = current {
            total += node.value;
            count += 1;
            current = &node.next;
        }
        if count != 0 {
            total as f64 / count as f64
        } else {
            0.0
        }
    }
}

struct ConsensusMechanics {
    ledger: Ledger,
}

impl ConsensusMechanics {
    fn new() -> Self {
        ConsensusMechanics {
            ledger: Ledger::new(),
        }
    }

    fn update_ledger(&mut self, value: i32) {
        self.ledger.append(value);
    }

    fn run_consensus(&mut self) {
        loop {
            let consensus_value = self.ledger.calculate_consensus();
            self.update_ledger(consensus_value as i32);
        }
    }
}

fn main() {
    let mut mechanics = ConsensusMechanics::new();
    for i in 0..10 {
        mechanics.update_ledger(i);
    }
    mechanics.run_consensus();
}