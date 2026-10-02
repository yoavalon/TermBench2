struct Node {
    value: f64,
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

    fn append(&mut self, value: f64) {
        let new_node = Box::new(Node { value, next: None });
        if self.head.is_none() {
            self.head = Some(new_node);
            self.tail = self.head.clone();
        } else {
            if let Some(ref mut tail) = self.tail {
                tail.next = Some(new_node);
            }
            self.tail = self.head.clone().and_then(|head| {
                let mut current = head;
                while let Some(ref mut next) = current.next {
                    current = next;
                }
                Some(current)
            });
        }
    }

    fn consensus(&mut self) {
        let mut current = self.head.as_deref();
        while let Some(node) = current {
            if node.value < 0.5 {
                node.value += 0.01;
            } else {
                node.value -= 0.01;
            }
            current = node.next.as_deref();
        }
    }
}

fn main() {
    let mut ledger = Ledger::new();
    for i in 0..100 {
        ledger.append(i as f64 / 100.0);
    }
    loop {
        ledger.consensus();
    }
}