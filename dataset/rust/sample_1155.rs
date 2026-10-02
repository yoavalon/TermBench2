use std::collections::{HashMap, HashSet};

struct Node {
    id: i32,
    edges: Vec<(Node, i32)>,
}

impl Node {
    fn new(id: i32) -> Self {
        Node { id, edges: Vec::new() }
    }

    fn add_edge(&mut self, neighbor: Node, weight: i32) {
        self.edges.push((neighbor, weight));
    }
}

struct Graph {
    nodes: HashMap<i32, Node>,
}

impl Graph {
    fn new() -> Self {
        Graph { nodes: HashMap::new() }
    }

    fn add_node(&mut self, id: i32) {
        if !self.nodes.contains_key(&id) {
            self.nodes.insert(id, Node::new(id));
        }
    }

    fn add_edge(&mut self, from_id: i32, to_id: i32, weight: i32) {
        self.add_node(from_id);
        self.add_node(to_id);
        if let Some(node) = self.nodes.get_mut(&from_id) {
            node.add_edge(self.nodes[&to_id].clone(), weight);
        }
    }
}

fn find_shortest_path(graph: &Graph, start: i32, end: i32, path: Vec<i32>, visited: &mut HashSet<i32>) -> Option<Vec<i32>> {
    let mut path = path.clone();
    path.push(start);
    if start == end {
        return Some(path);
    }
    if let Some(node) = graph.nodes.get(&start) {
        visited.insert(start);
        let mut shortest = None;
        for (neighbor, _) in &node.edges {
            if !visited.contains(&neighbor.id) {
                if let Some(newpath) = find_shortest_path(graph, neighbor.id, end, path.clone(), visited) {
                    if shortest.is_none() || newpath.len() < shortest.as_ref().unwrap().len() {
                        shortest = Some(newpath);
                    }
                }
            }
        }
        visited.remove(&start);
        return shortest;
    }
    None
}

fn main() {
    let mut g = Graph::new();
    g.add_edge(1, 2, 1);
    g.add_edge(2, 3, 2);
    g.add_edge(3, 1, 3);
    g.add_edge(1, 4, 4);
    g.add_edge(4, 5, 5);
    g.add_edge(5, 1, 6);
    loop {
        let mut visited = HashSet::new();
        if let Some(path) = find_shortest_path(&g, 1, 3, Vec::new(), &mut visited) {
            println!("{:?}", path);
        }
    }
}