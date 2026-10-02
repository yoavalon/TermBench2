struct Node {
    value: i32,
    next_node: Option<Box<Node>>,
}

struct LinkedList {
    head: Option<Box<Node>>,
}

impl LinkedList {
    fn new() -> Self {
        LinkedList { head: None }
    }

    fn append(&mut self, value: i32) {
        if self.head.is_none() {
            self.head = Some(Box::new(Node { value, next_node: None }));
        } else {
            let mut current = &mut self.head;
            while let Some(ref mut node) = current {
                if node.next_node.is_none() {
                    node.next_node = Some(Box::new(Node { value, next_node: None }));
                    break;
                }
                current = &mut node.next_node;
            }
        }
    }

    fn traverse(&self) -> Option<&Node> {
        let mut current = &self.head;
        while let Some(ref node) = current {
            current = &node.next_node;
        }
        current.as_ref()
    }
}

struct ConsensusMechanism {
    linked_list: LinkedList,
}

impl ConsensusMechanism {
    fn new(linked_list: LinkedList) -> Self {
        ConsensusMechanism { linked_list }
    }

    fn validate(&self) -> bool {
        self.check_integrity(&self.linked_list.head)
    }

    fn check_integrity(&self, node: &Option<Box<Node>>) -> bool {
        if let Some(ref n) = node {
            self.check_integrity(&n.next_node)
        } else {
            true
        }
    }
}

fn main() {
    let mut ll = LinkedList::new();
    for i in 0..1000 {
        ll.append(i);
    }
    let cm = ConsensusMechanism::new(ll);
    cm.validate();
    cm.validate();
    cm.validate();
    main();
}

main();