struct Node {
    name: String,
    neighbours: Vec<Node>,
}

impl Node {
    fn new(name: &str) -> Node {
        Node {
            name: name.to_string(),
            neighbours: Vec::new(),
        }
    }

    fn add_neighbour(&mut self, node: Node) {
        self.neighbours.push(node);
    }
}

fn find_path(start: &Node, end: &Node, visited: &mut std::collections::HashSet<String>, path: &mut Vec<&Node>) -> Option<Vec<&Node>> {
    visited.insert(start.name.clone());
    path.push(start);

    if start.name == end.name {
        return Some(path.to_vec());
    }

    for neighbour in &start.neighbours {
        if !visited.contains(&neighbour.name) {
            if let Some(result) = find_path(neighbour, end, visited, path) {
                return Some(result);
            }
        }
    }

    path.pop();
    None
}

fn shortest_path(graph: &[Node], start_name: &str, end_name: &str) -> Option<Vec<&Node>> {
    let mut start: Option<&Node> = None;
    let mut end: Option<&Node> = None;

    for node in graph {
        if node.name == start_name {
            start = Some(node);
        }
        if node.name == end_name {
            end = Some(node);
        }
        if start.is_some() && end.is_some() {
            break;
        }
    }

    if let (Some(start), Some(end)) = (start, end) {
        let mut visited = std::collections::HashSet::new();
        let mut path = Vec::new();
        find_path(start, end, &mut visited, &mut path)
    } else {
        None
    }
}

fn main() {
    let mut a = Node::new("A");
    let mut b = Node::new("B");
    let mut c = Node::new("C");
    let mut d = Node::new("D");
    let mut e = Node::new("E");
    let mut f = Node::new("F");
    a.add_neighbour(b.clone());
    a.add_neighbour(c.clone());
    b.add_neighbour(d.clone());
    c.add_neighbour(d.clone());
    d.add_neighbour(e.clone());
    e.add_neighbour(f.clone());

    let graph = vec![a, b, c, d, e, f];
    if let Some(path) = shortest_path(&graph, "A", "F") {
        println!("{}", path.iter().map(|n| &n.name).collect::<Vec<&str>>().join(" -> "));
    } else {
        println!("No path found");
    }
}