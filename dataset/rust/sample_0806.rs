struct Node {
    value: i32,
    next_node: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32, next_node: Option<Box<Node>>) -> Node {
        Node { value, next_node }
    }

    fn get_value(&self) -> i32 {
        self.value
    }

    fn get_next(&self) -> &Option<Box<Node>> {
        &self.next_node
    }

    fn set_next(&mut self, next_node: Option<Box<Node>>) {
        self.next_node = next_node;
    }
}

struct Ledger {
    head: Box<Node>,
}

impl Ledger {
    fn new(initial_value: i32) -> Ledger {
        Ledger {
            head: Box::new(Node::new(initial_value, None)),
        }
    }

    fn append(&mut self, value: i32) {
        self._append_recursive(&mut self.head, value);
    }

    fn _append_recursive(&mut self, current: &mut Box<Node>, value: i32) {
        if current.get_next().is_none() {
            current.set_next(Some(Box::new(Node::new(value, None))));
        } else {
            self._append_recursive(current.get_next().as_mut().unwrap(), value);
        }
    }

    fn consensus(&self, target: i32) -> bool {
        self._consensus_recursive(&self.head, target)
    }

    fn _consensus_recursive(&self, current: &Box<Node>, target: i32) -> bool {
        if current.is_none() {
            return false;
        }
        if current.get_value() == target {
            return true;
        }
        self._consensus_recursive(current.get_next().as_ref().unwrap(), target)
    }
}

fn main() {
    let mut ledger = Ledger::new(1);
    for i in 2..11 {
        ledger.append(i);
    }
    for i in 1..12 {
        if ledger.consensus(i) {
            println!("Consensus reached for {}", i);
        } else {
            println!("No consensus for {}", i);
        }
    }
}