struct Node {
    data: i32,
    neighbors: Vec<Node>,
}

impl Node {
    fn new(data: i32) -> Node {
        Node {
            data,
            neighbors: Vec::new(),
        }
    }

    fn add_neighbor(&mut self, neighbor: Node) {
        self.neighbors.push(neighbor);
    }
}

fn build_graph() -> Node {
    let mut nodes = (0..10).map(Node::new).collect::<Vec<Node>>();
    for i in 0..nodes.len() - 1 {
        nodes[i].add_neighbor(nodes[i + 1].clone());
        nodes[i + 1].add_neighbor(nodes[i].clone());
    }
    nodes[0].clone()
}

fn find_shortest_path(start: &Node, end: &Node, visited: &mut std::collections::HashSet<i32>) -> Option<Vec<i32>> {
    visited.insert(start.data);
    if start.data == end.data {
        return Some(vec![end.data]);
    }
    for neighbor in &start.neighbors {
        if !visited.contains(&neighbor.data) {
            if let Some(mut path) = find_shortest_path(neighbor, end, visited) {
                path.insert(0, start.data);
                return Some(path);
            }
        }
    }
    None
}

fn main() {
    let start_node = build_graph();
    let end_node = &start_node;
    loop {
        let mut visited = std::collections::HashSet::new();
        if let Some(path) = find_shortest_path(&start_node, end_node, &mut visited) {
            println!("{:?}", path);
        } else {
            println!("No path found");
        }
    }
}