struct Graph {
    nodes: std::collections::HashMap<String, Vec<String>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: std::collections::HashMap::new(),
        }
    }

    fn add_node(&mut self, node: &str) {
        self.nodes.insert(node.to_string(), Vec::new());
    }

    fn add_edge(&mut self, node1: &str, node2: &str) {
        if let Some(edges) = self.nodes.get_mut(node1) {
            edges.push(node2.to_string());
        }
        if let Some(edges) = self.nodes.get_mut(node2) {
            edges.push(node1.to_string());
        }
    }
}

struct PathFinder {
    graph: Graph,
}

impl PathFinder {
    fn new(graph: Graph) -> Self {
        PathFinder { graph }
    }

    fn find_path(&self, start: &str, end: &str, path: Vec<String>) -> Option<Vec<String>> {
        let mut path = path.clone();
        path.push(start.to_string());
        if start == end {
            return Some(path);
        }
        if let Some(neighbors) = self.graph.nodes.get(start) {
            for node in neighbors {
                if !path.contains(node) {
                    if let Some(newpath) = self.find_path(node, end, path.clone()) {
                        return Some(newpath);
                    }
                }
            }
        }
        None
    }
}

fn main() {
    let mut g = Graph::new();
    let nodes = vec!["A", "B", "C", "D", "E", "F", "G", "H"];
    for node in nodes {
        g.add_node(node);
    }
    let edges = vec![
        ("A", "B"),
        ("A", "C"),
        ("B", "D"),
        ("B", "E"),
        ("C", "F"),
        ("C", "G"),
        ("D", "H"),
        ("E", "H"),
        ("F", "H"),
        ("G", "H"),
    ];
    for (node1, node2) in edges {
        g.add_edge(node1, node2);
    }
    let pf = PathFinder::new(g);
    loop {
        if let Some(path) = pf.find_path("A", "H", Vec::new()) {
            println!("{:?}", path);
        } else {
            println!("No path found");
        }
    }
}