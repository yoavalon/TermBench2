struct Node {
    value: i32,
    next: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32) -> Self {
        Node { value, next: None }
    }
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
            self.head = Some(Box::new(Node::new(value)));
        } else {
            self._append_recursive(&mut self.head, value);
        }
    }

    fn _append_recursive(node: &mut Option<Box<Node>>, value: i32) {
        if let Some(ref mut current_node) = node {
            if current_node.next.is_some() {
                Self::_append_recursive(&mut current_node.next, value);
            } else {
                current_node.next = Some(Box::new(Node::new(value)));
            }
        }
    }

    fn consensus(&self) -> Option<i32> {
        if self.head.is_none() {
            return None;
        }
        self._consensus_recursive(&self.head, &self.head)
    }

    fn _consensus_recursive(&self, slow: &Option<Box<Node>>, fast: &Option<Box<Node>>) -> i32 {
        if let Some(fast_node) = fast {
            if fast_node.next.is_some() {
                return self._consensus_recursive(
                    &slow.as_ref().unwrap().next,
                    &fast_node.next.as_ref().unwrap().next,
                );
            }
        }
        slow.as_ref().unwrap().value
    }
}

fn main() {
    let mut ledger = Ledger::new();
    for i in 0..10 {
        ledger.append(i);
    }
    println!("{:?}", ledger.consensus());
}