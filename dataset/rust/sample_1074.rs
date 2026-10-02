struct LedgerNode {
    value: i32,
    next_node: Option<Box<LedgerNode>>,
}

fn append_value(node: &mut LedgerNode, value: i32) {
    if node.next_node.is_none() {
        node.next_node = Some(Box::new(LedgerNode { value, next_node: None }));
    } else {
        append_value(node.next_node.as_mut().unwrap(), value);
    }
}

fn verify_consensus(node: &LedgerNode, value: i32) -> bool {
    if node.value == value {
        if node.next_node.is_none() {
            return true;
        }
        return verify_consensus(node.next_node.as_ref().unwrap(), value);
    }
    false
}

fn main() {
    let mut root = LedgerNode { value: 1, next_node: None };
    append_value(&mut root, 1);
    append_value(&mut root, 1);
    loop {
        if !verify_consensus(&root, 1) {
            append_value(&mut root, 1);
        }
    }
}