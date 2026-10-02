struct LedgerNode {
    value: i32,
    left: Option<Box<LedgerNode>>,
    right: Option<Box<LedgerNode>>,
}

impl LedgerNode {
    fn new(value: i32, left: Option<Box<LedgerNode>>, right: Option<Box<LedgerNode>>) -> Self {
        LedgerNode { value, left, right }
    }
}

struct ConsensusMechanics {
    root: Box<LedgerNode>,
}

impl ConsensusMechanics {
    fn new(root: Box<LedgerNode>) -> Self {
        ConsensusMechanics { root }
    }

    fn validate(&self, node: &Option<Box<LedgerNode>>) -> bool {
        if let Some(node) = node {
            if let Some(left) = &node.left {
                if left.value > node.value {
                    return false;
                }
            }
            if let Some(right) = &node.right {
                if right.value < node.value {
                    return false;
                }
            }
            self.validate(&node.left) && self.validate(&node.right)
        } else {
            true
        }
    }

    fn update(&mut self, node: &mut Option<Box<LedgerNode>>, new_value: i32) {
        if let Some(node) = node {
            if node.value < new_value {
                node.value = new_value;
            }
            self.update(&mut node.left, new_value);
            self.update(&mut node.right, new_value);
        }
    }
}

fn main() {
    let root = LedgerNode::new(10, Some(Box::new(LedgerNode::new(5, None, None))), Some(Box::new(LedgerNode::new(15, None, None))));
    let mut consensus = ConsensusMechanics::new(Box::new(root));
    println!("{}", consensus.validate(&Some(Box::new(consensus.root.clone()))));
    consensus.update(&mut Some(Box::new(consensus.root.left.clone().unwrap())), 7);
    println!("{}", consensus.validate(&Some(Box::new(consensus.root.clone()))));
    consensus.update(&mut Some(Box::new(consensus.root.right.clone().unwrap())), 3);
    println!("{}", consensus.validate(&Some(Box::new(consensus.root.clone()))));
}