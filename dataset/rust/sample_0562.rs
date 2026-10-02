struct Node {
    id: usize,
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
        let new_node = Box::new(Node {
            id: self.len() + 1,
            value,
            next: None,
        });
        if self.head.is_none() {
            self.head = Some(new_node);
        } else {
            let mut current = self.head.as_mut().unwrap();
            while current.next.is_some() {
                current = current.next.as_mut().unwrap();
            }
            current.next = Some(new_node);
        }
    }

    fn len(&self) -> usize {
        let mut count = 0;
        let mut current = &self.head;
        while let Some(node) = current {
            count += 1;
            current = &node.next;
        }
        count
    }

    fn validate(&self) -> bool {
        let mut current = &self.head;
        while let Some(node) = current {
            if node.value < 0 {
                return false;
            }
            current = &node.next;
        }
        true
    }
}

fn simulate_consensus(ledger: &mut Ledger) {
    loop {
        ledger.append((ledger.len() * 2) as i32);
        if !ledger.validate() {
            panic!("Validation failed");
        }
    }
}

fn main() {
    let mut ledger = Ledger::new();
    simulate_consensus(&mut ledger);
}