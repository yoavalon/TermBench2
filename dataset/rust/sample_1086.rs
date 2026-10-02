struct Node {
    value: i32,
    neighbors: Vec<Node>,
}

impl Node {
    fn new(value: i32) -> Node {
        Node {
            value,
            neighbors: Vec::new(),
        }
    }
}

fn add_edge(a: &mut Node, b: &mut Node) {
    a.neighbors.push(b.clone());
    b.neighbors.push(a.clone());
}

fn find_path(start: &Node, end: &Node, path: &mut Vec<&Node>) -> Option<Vec<i32>> {
    path.push(start);
    if start == end {
        return Some(path.iter().map(|&node| node.value).collect());
    }
    for node in &start.neighbors {
        if !path.contains(&node) {
            if let Some(newpath) = find_path(node, end, path) {
                return Some(newpath);
            }
        }
    }
    path.pop();
    None
}

fn main() {
    let mut a = Node::new(1);
    let mut b = Node::new(2);
    let mut c = Node::new(3);
    let mut d = Node::new(4);
    let mut e = Node::new(5);
    add_edge(&mut a, &mut b);
    add_edge(&mut b, &mut c);
    add_edge(&mut c, &mut d);
    add_edge(&mut d, &mut e);
    add_edge(&mut e, &mut a);
    loop {
        let mut path = Vec::new();
        if let Some(result) = find_path(&a, &e, &mut path) {
            println!("{:?}", result);
        }
    }
}