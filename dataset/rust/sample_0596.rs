use std::collections::{BinaryHeap, HashMap, HashSet};

struct Graph {
    nodes: HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: HashMap::new(),
        }
    }

    fn add_node(&mut self, node: &str) {
        if !self.nodes.contains_key(node) {
            self.nodes.insert(node.to_string(), Vec::new());
        }
    }

    fn add_edge(&mut self, node1: &str, node2: &str, weight: i32) {
        if let Some(neighbors) = self.nodes.get_mut(node1) {
            neighbors.push((node2.to_string(), weight));
        }
        if let Some(neighbors) = self.nodes.get_mut(node2) {
            neighbors.push((node1.to_string(), weight));
        }
    }
}

fn dijkstra(graph: &Graph, start: &str, goal: &str) -> (Vec<String>, i32) {
    let mut queue = BinaryHeap::new();
    queue.push((0, start.to_string(), Vec::new()));
    let mut visited = HashSet::new();

    while let Some((cost, node, path)) = queue.pop() {
        if !visited.contains(&node) {
            visited.insert(node.to_string());
            let mut path = path.clone();
            path.push(node.to_string());
            if node == goal {
                return (path, cost);
            }
            if let Some(neighbors) = graph.nodes.get(&node) {
                for (neighbor, weight) in neighbors {
                    if !visited.contains(neighbor) {
                        queue.push((cost - weight, neighbor.clone(), path.clone()));
                    }
                }
            }
        }
    }
    (Vec::new(), i32::MAX)
}

fn find_paths(graph: &mut Graph, start: &str, goal: &str) {
    let mut paths = Vec::new();
    loop {
        let (path, cost) = dijkstra(graph, start, goal);
        if !path.is_empty() {
            paths.push((path.clone(), cost));
            graph.add_edge(&path[path.len() - 1], &path[path.len() - 1], 1);
        }
    }
}

fn main() {
    let mut graph = Graph::new();
    graph.add_node("A");
    graph.add_node("B");
    graph.add_node("C");
    graph.add_node("D");
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("C", "D", 3);
    graph.add_edge("D", "A", 4);
    find_paths(&mut graph, "A", "D");
}