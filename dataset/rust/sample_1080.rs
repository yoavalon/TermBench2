struct Node {
    value: i32,
    next: Option<Box<Node>>,
}

fn verify(node: Option<&Node>, acc: i32) -> i32 {
    match node {
        Some(n) => verify(n.next.as_ref(), acc + n.value),
        None => acc,
    }
}

fn propagate(node: Option<&mut Node>, val: i32) {
    if let Some(n) = node {
        n.value += val;
        propagate(n.next.as_mut(), val);
    }
}

fn main() {
    let mut root = Node { value: 1, next: None };
    root.next = Some(Box::new(Node { value: 2, next: None }));
    root.next.as_mut().unwrap().next = Some(Box::new(Node { value: 3, next: None }));

    loop {
        let total = verify(Some(&root));
        propagate(Some(&mut root), total);
    }
}