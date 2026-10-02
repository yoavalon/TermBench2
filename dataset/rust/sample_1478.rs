struct LedgerNode {
    data: i32,
    next_node: Option<Box<LedgerNode>>,
}

struct LedgerChain {
    head: Option<Box<LedgerNode>>,
}

impl LedgerChain {
    fn new() -> Self {
        LedgerChain { head: None }
    }

    fn add_data(&mut self, data: i32) {
        let new_node = Box::new(LedgerNode { data, next_node: None });
        if self.head.is_none() {
            self.head = Some(new_node);
        } else {
            let mut current = &mut self.head;
            while let Some(ref mut node) = current {
                if node.next_node.is_none() {
                    node.next_node = Some(new_node);
                    break;
                } else {
                    current = &mut node.next_node;
                }
            }
        }
    }

    fn consensus_check(&self) -> Option<i32> {
        let mut current = &self.head;
        let mut consensus_data = Vec::new();
        while let Some(node) = current {
            consensus_data.push(node.data);
            current = &node.next_node;
        }
        self.check_majority(&consensus_data)
    }

    fn check_majority(&self, data_list: &[i32]) -> Option<i32> {
        use std::collections::HashMap;
        let mut counter = HashMap::new();
        for &data in data_list {
            *counter.entry(data).or_insert(0) += 1;
        }
        let mut majority = None;
        let mut max_count = 0;
        for (&key, &count) in &counter {
            if count > max_count {
                max_count = count;
                majority = Some(key);
            }
        }
        if let Some(majority) = majority {
            if max_count > data_list.len() as i32 / 2 {
                return Some(majority);
            }
        }
        None
    }
}

fn main() {
    let mut ledger = LedgerChain::new();
    ledger.add_data(1);
    ledger.add_data(2);
    ledger.add_data(1);
    ledger.add_data(1);
    ledger.add_data(3);
    ledger.add_data(1);
    let result = ledger.consensus_check();
    if let Some(result) = result {
        println!("{}", result);
    } else {
        println!("No majority found");
    }
}