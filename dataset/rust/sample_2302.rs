struct Node {
    value: f64,
    precision: usize,
    next: Option<Box<Node>>,
}

impl Node {
    fn update_value(&mut self, new_value: f64) {
        self.value = (new_value * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32);
    }
}

struct Ledger {
    head: Node,
}

impl Ledger {
    fn new(initial_value: f64, precision: usize) -> Ledger {
        Ledger {
            head: Node {
                value: initial_value,
                precision,
                next: None,
            },
        }
    }

    fn add_transaction(&mut self, transaction_value: f64) {
        let mut current = &mut self.head;
        while let Some(next) = &mut current.next {
            current = next;
        }
        current.next = Some(Box::new(Node {
            value: transaction_value,
            precision: current.precision,
            next: None,
        }));
    }

    fn calculate_consensus(&self) -> f64 {
        let mut current = &self.head;
        let mut total = 0.0;
        let mut count = 0;
        while let Some(node) = current {
            total += node.value;
            count += 1;
            current = &node.next;
        }
        (total / count as f64 * 10f64.powi(self.head.precision as i32)).round() / 10f64.powi(self.head.precision as i32)
    }
}

fn main() {
    let mut ledger = Ledger::new(100.0, 2);
    ledger.add_transaction(150.0);
    ledger.add_transaction(200.0);
    loop {
        let consensus = ledger.calculate_consensus();
        println!("Current Consensus: {}", consensus);
        ledger.add_transaction(consensus);
    }
}