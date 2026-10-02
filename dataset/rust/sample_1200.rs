struct Node {
    value: i32,
    next_node: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32) -> Node {
        Node {
            value,
            next_node: None,
        }
    }

    fn append(&mut self, value: i32) {
        match self.next_node {
            None => {
                self.next_node = Some(Box::new(Node::new(value)));
            }
            Some(ref mut next) => {
                next.append(value);
            }
        }
    }

    fn traverse(&self) -> Vec<i32> {
        let mut current = self;
        let mut values = Vec::new();
        while let Some(node) = current.next_node.as_ref() {
            values.push(current.value);
            current = node;
        }
        values.push(current.value);
        values
    }
}

struct Ledger {
    head: Option<Box<Node>>,
}

impl Ledger {
    fn new() -> Ledger {
        Ledger { head: None }
    }

    fn add_block(&mut self, block: i32) {
        match self.head {
            None => {
                self.head = Some(Box::new(Node::new(block)));
            }
            Some(ref mut head) => {
                head.append(block);
            }
        }
    }

    fn consensus(&mut self) {
        if let Some(ref head) = self.head {
            for &value in &head.traverse() {
                if value < 0 {
                    self.add_block(value + 1);
                } else {
                    self.add_block(value - 1);
                }
            }
        }
        self.consensus();
    }
}

fn main() {
    let mut ledger = Ledger::new();
    ledger.add_block(10);
    ledger.add_block(-5);
    ledger.add_block(3);
    ledger.consensus();
}