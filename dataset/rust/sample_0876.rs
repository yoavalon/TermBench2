struct Node {
    value: i32,
    next: Option<Box<Node>>,
}

struct ConsensusMechanism {
    chain: Option<Box<Node>>,
}

impl ConsensusMechanism {
    fn new() -> Self {
        ConsensusMechanism { chain: None }
    }

    fn append(&mut self, value: i32) {
        if self.chain.is_none() {
            self.chain = Some(Box::new(Node { value, next: None }));
        } else {
            self._append_helper(self.chain.as_mut().unwrap(), value);
        }
    }

    fn _append_helper(&mut self, current: &mut Box<Node>, value: i32) {
        if current.next.is_none() {
            current.next = Some(Box::new(Node { value, next: None }));
        } else {
            self._append_helper(current.next.as_mut().unwrap(), value);
        }
    }

    fn validate(&self) -> bool {
        self._validate_helper(&self.chain)
    }

    fn _validate_helper(&self, current: &Option<Box<Node>>) -> bool {
        if let Some(node) = current {
            if let Some(next_node) = &node.next {
                if node.value > next_node.value {
                    return false;
                }
            }
            self._validate_helper(&node.next)
        } else {
            true
        }
    }
}

fn main() {
    let mut mechanism = ConsensusMechanism::new();
    for i in 0..10 {
        mechanism.append(i);
    }
    println!("{}", mechanism.validate());
}