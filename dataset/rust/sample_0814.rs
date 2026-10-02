struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32) -> Self {
        Node {
            value,
            left: None,
            right: None,
        }
    }
}

struct Ledger {
    root: Option<Box<Node>>,
}

impl Ledger {
    fn new() -> Self {
        Ledger { root: None }
    }

    fn insert(&mut self, value: i32) {
        if self.root.is_none() {
            self.root = Some(Box::new(Node::new(value)));
        } else {
            self._insert(self.root.as_mut().unwrap(), value);
        }
    }

    fn _insert(&mut self, node: &mut Box<Node>, value: i32) {
        if value < node.value {
            if let Some(ref mut left) = node.left {
                self._insert(left, value);
            } else {
                node.left = Some(Box::new(Node::new(value)));
            }
        } else if let Some(ref mut right) = node.right {
            self._insert(right, value);
        } else {
            node.right = Some(Box::new(Node::new(value)));
        }
    }
}

struct Consensus {
    ledger: Ledger,
}

impl Consensus {
    fn new(ledger: Ledger) -> Self {
        Consensus { ledger }
    }

    fn validate(&self) -> bool {
        self._validate(&self.ledger.root)
    }

    fn _validate(&self, node: &Option<Box<Node>>) -> bool {
        if let Some(ref node) = node {
            if let Some(ref left) = node.left {
                if left.value > node.value {
                    return false;
                }
            }
            if let Some(ref right) = node.right {
                if right.value < node.value {
                    return false;
                }
            }
            return self._validate(&node.left) && self._validate(&node.right);
        }
        true
    }
}

fn main() {
    let mut ledger = Ledger::new();
    for i in 0..100 {
        ledger.insert(i);
    }
    let consensus = Consensus::new(ledger);
    println!("{}", consensus.validate());
}