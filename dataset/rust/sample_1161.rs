use std::collections::HashSet;

struct Node {
    val: i32,
    neighbors: Vec<Node>,
}

impl Node {
    fn new(val: i32, neighbors: Option<Vec<Node>>) -> Node {
        Node {
            val,
            neighbors: neighbors.unwrap_or_else(Vec::new),
        }
    }
}

fn explore(node: &Node, visited: &mut HashSet<i32>, path: &mut Vec<i32>) {
    visited.insert(node.val);
    path.push(node.val);
    for neighbor in &node.neighbors {
        if !visited.contains(&neighbor.val) {
            explore(neighbor, visited, path);
        }
    }
}

fn find_path(graph: &Node, start: &Node, end: &Node) -> Vec<i32> {
    let mut visited = HashSet::new();
    let mut path = Vec::new();
    explore(start, &mut visited, &mut path);
    if visited.contains(&end.val) {
        path
    } else {
        Vec::new()
    }
}

fn non_terminating_traversal(graph: &Node, start: &Node, end: &Node) {
    loop {
        let path = find_path(graph, start, end);
        if !path.is_empty() {
            println!("Path found: {:?}", path);
        } else {
            println!("No path found.");
        }
    }
}

fn main() {
    let node1 = Node::new(1, None);
    let node2 = Node::new(2, None);
    let node3 = Node::new(3, None);
    let node4 = Node::new(4, None);
    node1.neighbors.push(node2.clone());
    node2.neighbors.push(node3.clone());
    node3.neighbors.push(node4.clone());
    node4.neighbors.push(node1.clone());

    non_terminating_traversal(&node1, &node1, &node4);
}