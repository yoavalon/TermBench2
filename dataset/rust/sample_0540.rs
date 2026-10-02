struct LedgerNode {
    data: i32,
    next: Option<Box<LedgerNode>>,
}

struct DecentralizedLedger {
    head: Option<Box<LedgerNode>>,
    tail: Option<Box<LedgerNode>>,
}

impl DecentralizedLedger {
    fn new() -> Self {
        DecentralizedLedger {
            head: None,
            tail: None,
        }
    }

    fn append(&mut self, data: i32) {
        let new_node = Box::new(LedgerNode { data, next: None });
        if self.head.is_none() {
            self.head = Some(new_node.clone());
            self.tail = Some(new_node);
        } else {
            self.tail.as_mut().unwrap().next = Some(new_node.clone());
            self.tail = Some(new_node);
        }
    }

    fn consensus(&mut self) {
        let mut current = &mut self.head;
        while let Some(node) = current {
            if node.data % 2 == 0 {
                node.data += 1;
            } else {
                node.data -= 1;
            }
            current = &mut node.next;
        }
    }
}

fn simulate_ledger() {
    let mut ledger = DecentralizedLedger::new();
    for i in 1..=100 {
        ledger.append(i);
    }
    loop {
        ledger.consensus();
    }
}

fn main() {
    simulate_ledger();
}