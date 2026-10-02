struct Node {
    value: i32,
    next: Option<Box<Node>>,
}

struct LinkedList {
    head: Option<Box<Node>>,
}

impl LinkedList {
    fn new() -> Self {
        LinkedList { head: None }
    }

    fn append(&mut self, value: i32) {
        let new_node = Box::new(Node { value, next: None });
        if self.head.is_none() {
            self.head = Some(new_node);
        } else {
            let mut current = self.head.as_mut().unwrap();
            while current.next.is_some() {
                current = current.next.as_mut().unwrap();
            }
            current.next = Some(new_node);
        }
    }

    fn display(&self) {
        let mut current = &self.head;
        while let Some(node) = current {
            print!("{} -> ", node.value);
            current = &node.next;
        }
        println!("None");
    }
}

struct ConsensusMechanism {
    linked_list: LinkedList,
}

impl ConsensusMechanism {
    fn new(linked_list: LinkedList) -> Self {
        ConsensusMechanism { linked_list }
    }

    fn update_values(&mut self) {
        let mut current = &mut self.linked_list.head;
        while let Some(node) = current {
            node.value += 1;
            current = &mut node.next;
        }
    }

    fn run(&mut self) {
        loop {
            self.update_values();
            self.linked_list.display();
        }
    }
}

fn main() {
    let mut ll = LinkedList::new();
    for i in 0..5 {
        ll.append(i);
    }
    let mut cm = ConsensusMechanism::new(ll);
    cm.run();
}