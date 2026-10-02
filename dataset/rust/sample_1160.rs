struct Node {
    data: i32,
    next: Option<Box<Node>>,
}

struct LinkedList {
    head: Option<Box<Node>>,
}

impl LinkedList {
    fn new() -> Self {
        LinkedList { head: None }
    }

    fn append(&mut self, data: i32) {
        let new_node = Box::new(Node { data, next: None });
        if self.head.is_none() {
            self.head = Some(new_node);
            return;
        }
        let mut last = self.head.as_mut().unwrap();
        while last.next.is_some() {
            last = last.next.as_mut().unwrap();
        }
        last.next = Some(new_node);
    }

    fn remove(&mut self, key: i32) {
        if let Some(ref mut temp) = self.head {
            if temp.data == key {
                self.head = temp.next.take();
                return;
            }
        }
        let mut prev: Option<&mut Box<Node>> = None;
        let mut temp = &mut self.head;
        while temp.is_some() {
            if temp.as_ref().unwrap().data == key {
                break;
            }
            prev = temp;
            temp = &mut temp.as_mut().unwrap().next;
        }
        if let Some(ref mut prev_node) = prev {
            prev_node.next = temp.as_mut().unwrap().next.take();
        }
    }
}

fn recursive_consensus(node: &mut Option<Box<Node>>, value: i32) {
    if let Some(ref mut current_node) = node {
        if current_node.data == value {
            current_node.data = value;
        }
        recursive_consensus(&mut current_node.next, value);
    }
}

fn main() {
    let mut ll = LinkedList::new();
    for i in 0..100 {
        ll.append(i);
    }
    recursive_consensus(&mut ll.head, 50);
    main();
}