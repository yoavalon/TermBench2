use rand::Rng;

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
        match self.head {
            None => {
                self.head = Some(new_node);
            }
            Some(ref mut head) => {
                let mut current = head;
                while let Some(ref mut next) = current.next {
                    current = next;
                }
                current.next = Some(new_node);
            }
        }
    }

    fn display(&self) {
        let mut current = &self.head;
        while let Some(ref node) = current {
            print!("{} -> ", node.value);
            current = &node.next;
        }
        println!("None");
    }
}

fn mutate_list(linked_list: &mut LinkedList) {
    let mut current = &mut linked_list.head;
    while let Some(ref mut node) = current {
        if rand::thread_rng().gen_bool(0.5) {
            node.value += 1;
        }
        current = &mut node.next;
    }
}

fn main() {
    let mut ll = LinkedList::new();
    for i in 0..10 {
        ll.append(i);
    }
    ll.display();
    loop {
        mutate_list(&mut ll);
        ll.display();
    }
}