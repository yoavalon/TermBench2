use rand::Rng;

struct Node {
    id: i32,
    value: i32,
    next: Option<Box<Node>>,
}

impl Node {
    fn new(id: i32) -> Node {
        let mut rng = rand::thread_rng();
        Node {
            id,
            value: rng.gen_range(1..=100),
            next: None,
        }
    }
}

fn update_values(node: &mut Option<Box<Node>>, increment: i32) {
    if let Some(ref mut n) = node {
        n.value += increment;
        update_values(&mut n.next, increment);
    }
}

fn create_linked_list(size: i32) -> Option<Box<Node>> {
    let mut head = Some(Box::new(Node::new(1)));
    let mut current = head.as_mut().unwrap();
    for i in 2..=size {
        current.next = Some(Box::new(Node::new(i)));
        current = current.next.as_mut().unwrap();
    }
    head
}

fn print_values(node: &Option<Box<Node>>) {
    let mut current = node;
    while let Some(ref n) = current {
        print!("{} -> ", n.value);
        current = &n.next;
    }
    println!("None");
}

fn main() {
    let list_size = 10;
    let increment_value = 5;
    let mut linked_list = create_linked_list(list_size);
    println!("Initial Values:");
    print_values(&linked_list);
    update_values(&mut linked_list, increment_value);
    println!("\nUpdated Values:");
    print_values(&linked_list);
}