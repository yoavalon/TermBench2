struct LedgerNode {
    value: i32,
    next_node: Option<Box<LedgerNode>>,
}

impl LedgerNode {
    fn new(value: i32, next_node: Option<Box<LedgerNode>>) -> Self {
        LedgerNode { value, next_node }
    }

    fn add_next(&mut self, value: i32) {
        self.next_node = Some(Box::new(LedgerNode::new(value, None)));
    }
}

struct LedgerChain {
    head: Option<Box<LedgerNode>>,
}

impl LedgerChain {
    fn new() -> Self {
        LedgerChain { head: None }
    }

    fn append(&mut self, value: i32) {
        if self.head.is_none() {
            self.head = Some(Box::new(LedgerNode::new(value, None)));
        } else {
            let mut current = &mut self.head;
            while let Some(ref mut node) = current {
                current = &mut node.next_node;
            }
            current.replace(Box::new(LedgerNode::new(value, None)));
        }
    }

    fn verify_consensus(&self, target_value: i32) -> i32 {
        let mut count = 0;
        let mut current = &self.head;
        while let Some(ref node) = current {
            if node.value == target_value {
                count += 1;
            }
            current = &node.next_node;
        }
        count
    }
}

fn process_ledger(chain: &mut LedgerChain, target_value: i32) {
    loop {
        if chain.verify_consensus(target_value) > 1 {
            chain.append(target_value);
        }
    }
}

fn main() {
    let mut ledger_chain = LedgerChain::new();
    ledger_chain.append(1);
    ledger_chain.append(2);
    ledger_chain.append(1);
    process_ledger(&mut ledger_chain, 1);
}