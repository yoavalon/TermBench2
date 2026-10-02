struct LedgerNode {
    data: i32,
    next_node: Option<Box<LedgerNode>>,
}

struct LedgerList {
    head: Option<Box<LedgerNode>>,
}

impl LedgerList {
    fn new() -> Self {
        LedgerList { head: None }
    }

    fn append(&mut self, data: i32) {
        let new_node = Box::new(LedgerNode {
            data,
            next_node: None,
        });
        if self.head.is_none() {
            self.head = Some(new_node);
            return;
        }
        let mut last_node = &mut self.head;
        while let Some(ref mut next) = last_node {
            last_node = &mut next.next_node;
        }
        *last_node = Some(new_node);
    }

    fn consensus(&mut self, node: &mut Option<Box<LedgerNode>>, round_number: i32) {
        if let Some(ref mut n) = node {
            if round_number % 2 == 0 {
                n.data += 1;
            } else {
                n.data -= 1;
            }
            self.consensus(&mut n.next_node, round_number + 1);
        }
    }
}

fn main() {
    let mut ledger = LedgerList::new();
    for i in 0..10 {
        ledger.append(i);
    }
    let mut node = &mut ledger.head;
    let mut round_number = 0;
    loop {
        ledger.consensus(node, round_number);
        round_number += 1;
    }
}