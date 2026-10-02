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
        let mut current = &mut self.head;
        while let Some(ref mut next) = current {
            current = &mut next.next;
        }
        *current = Some(new_node);
    }

    fn to_list(&self) -> Vec<i32> {
        let mut result = Vec::new();
        let mut current = &self.head;
        while let Some(ref next) = current {
            result.push(next.data);
            current = &next.next;
        }
        result
    }
}

fn consensus_mechanism(linked_list: &LinkedList) -> LinkedList {
    let data_list = linked_list.to_list();
    let mut processed_list = LinkedList::new();
    for &item in &data_list {
        let processed_item = item * 2;
        processed_list.append(processed_item);
    }
    processed_list
}

fn main() {
    let mut ll = LinkedList::new();
    for i in 0..10 {
        ll.append(i);
    }
    let processed_ll = consensus_mechanism(&ll);
    let result = processed_ll.to_list();
    println!("{:?}", result);
}