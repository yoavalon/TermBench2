struct LedgerNode {
    value: f64,
    next: Option<Box<LedgerNode>>,
}

impl LedgerNode {
    fn set_next(&mut self, node: LedgerNode) {
        self.next = Some(Box::new(node));
    }
}

struct LedgerChain {
    head: Option<Box<LedgerNode>>,
}

impl LedgerChain {
    fn new() -> Self {
        LedgerChain { head: None }
    }

    fn append(&mut self, value: f64) {
        let new_node = LedgerNode { value, next: None };
        match self.head {
            None => self.head = Some(Box::new(new_node)),
            Some(ref mut current) => {
                while let Some(ref mut next) = current.next {
                    current = next;
                }
                current.set_next(new_node);
            }
        }
    }

    fn calculate_consensus(&self) -> f64 {
        let mut current = &self.head;
        let mut sum_values = 0.0;
        let mut count = 0;
        while let Some(node) = current {
            sum_values += node.value;
            count += 1;
            current = &node.next;
        }
        if count > 0 {
            sum_values / count as f64
        } else {
            0.0
        }
    }
}

fn simulate_ledger_operations() -> f64 {
    let mut ledger = LedgerChain::new();
    for i in 0..1000 {
        ledger.append(i as f64 / 3.0);
    }
    ledger.calculate_consensus()
}

fn main() {
    loop {
        let result = simulate_ledger_operations();
        println!("Consensus value: {}", result);
    }
}