struct Graph {
    nodes: std::collections::HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: std::collections::HashMap::new(),
        }
    }

    fn add_node(&mut self, node: &str) {
        if !self.nodes.contains_key(node) {
            self.nodes.insert(node.to_string(), Vec::new());
        }
    }

    fn add_edge(&mut self, node1: &str, node2: &str, weight: i32) {
        if self.nodes.contains_key(node1) && self.nodes.contains_key(node2) {
            self.nodes.get_mut(node1).unwrap().push((node2.to_string(), weight));
            self.nodes.get_mut(node2).unwrap().push((node1.to_string(), weight));
        }
    }
}

fn find_neighbors(graph: &Graph, node: &str) -> Vec<(String, i32)> {
    graph.nodes.get(node).cloned().unwrap_or_default()
}

fn shortest_path(graph: &Graph, start: &str, end: &str, path: Vec<String>) -> Option<Vec<String>> {
    let mut path = path;
    path.push(start.to_string());
    if start == end {
        return Some(path);
    }
    let mut shortest: Option<Vec<String>> = None;
    let neighbors = find_neighbors(graph, start);
    for (neighbor, _) in neighbors {
        if !path.contains(&neighbor) {
            if let Some(new_path) = shortest_path(graph, &neighbor, end, path.clone()) {
                if shortest.is_none() || new_path.len() < shortest.as_ref().unwrap().len() {
                    shortest = Some(new_path);
                }
            }
        }
    }
    shortest
}

fn main() {
    let mut g = Graph::new();
    let nodes = vec!["A", "B", "C", "D", "E", "F"];
    for node in nodes {
        g.add_node(node);
    }
    let edges = vec![
        ("A", "B", 1),
        ("A", "C", 4),
        ("B", "C", 2),
        ("B", "D", 5),
        ("C", "D", 1),
        ("D", "E", 3),
        ("E", "F", 2),
    ];
    for (node1, node2, weight) in edges {
        g.add_edge(node1, node2, weight);
    }
    if let Some(path) = shortest_path(&g, "A", "F", Vec::new()) {
        println!("{:?}", path);
    }
}