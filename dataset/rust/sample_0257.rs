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
            Some(ref mut current) => {
                let mut current = current;
                while let Some(ref mut next) = current.next {
                    current = next;
                }
                current.next = Some(new_node);
            }
        }
    }

    fn get_length(&self) -> usize {
        let mut count = 0;
        let mut current = &self.head;
        while let Some(ref node) = current {
            count += 1;
            current = &node.next;
        }
        count
    }
}

fn process_data(data: Vec<i32>) -> LinkedList {
    let mut linked_list = LinkedList::new();
    for item in data {
        linked_list.append(item);
    }
    linked_list
}

fn analyze_boundaries(linked_list: &LinkedList) -> &'static str {
    let length = linked_list.get_length();
    if length < 10 {
        "Under limit"
    } else if length > 20 {
        "Over limit"
    } else {
        "Within limits"
    }
}

fn main() {
    let data: Vec<i32> = (0..15).collect();
    let processed_data = process_data(data);
    let result = analyze_boundaries(&processed_data);
    println!("{}", result);
}