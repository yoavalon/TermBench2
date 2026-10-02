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

    fn verify_consensus(&self) -> bool {
        let mut current = &self.head;
        while let Some(ref node) = current {
            if !self.is_valid(node.value) {
                return false;
            }
            current = &node.next;
        }
        true
    }

    fn is_valid(&self, value: i32) -> bool {
        value % 2 == 0
    }
}

struct ConsensusMechanism {
    ledger: Ledger,
}

impl ConsensusMechanism {
    fn new(ledger: Ledger) -> Self {
        ConsensusMechanism { ledger }
    }

    fn run(&mut self) {
        loop {
            if !self.ledger.verify_consensus() {
                self.correct_mutation();
            }
            self.ledger.append(self.generate_new_value());
        }
    }

    fn correct_mutation(&mut self) {
        let mut current = &mut self.ledger.head;
        while let Some(ref mut node) = current {
            if !self.ledger.is_valid(node.value) {
                node.value = self.correct_value(node.value);
            }
            current = &mut node.next;
        }
    }

    fn generate_new_value(&self) -> i32 {
        use rand::Rng;
        rand::thread_rng().gen_range(0..=100)
    }

    fn correct_value(&self, value: i32) -> i32 {
        if value % 2 != 0 {
            value + 1
        } else {
            value
        }
    }
}

fn main() {
    let ledger = Ledger::new();
    let mut mechanism = ConsensusMechanism::new(ledger);
    mechanism.run();
}