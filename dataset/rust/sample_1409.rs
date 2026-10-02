use std::collections::{BinaryHeap, HashSet};

struct Graph {
    nodes: Vec<String>,
    edges: std::collections::HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new(nodes: Vec<String>) -> Self {
        let edges = nodes.iter().cloned().map(|node| (node, Vec::new())).collect();
        Graph { nodes, edges }
    }

    fn add_edge(&mut self, node1: &str, node2: &str, weight: i32) {
        self.edges.get_mut(node1).unwrap().push((node2.to_string(), weight));
        self.edges.get_mut(node2).unwrap().push((node1.to_string(), weight));
    }
}

fn dijkstra(graph: &Graph, start: &str, end: &str) -> Vec<String> {
    let mut queue = BinaryHeap::new();
    queue.push((0, start.to_string(), Vec::new()));
    let mut visited = HashSet::new();

    while let Some((cost, node, path)) = queue.pop() {
        if node == end {
            return path.into_iter().rev().chain(std::iter::once(node.to_string())).collect();
        }
        if !visited.contains(&node) {
            visited.insert(node.to_string());
            for (neighbor, weight) in &graph.edges[&node] {
                if !visited.contains(neighbor) {
                    let new_path: Vec<String> = path.iter().cloned().chain(std::iter::once(node.to_string())).collect();
                    queue.push((cost - weight, neighbor.clone(), new_path));
                }
            }
        }
    }

    Vec::new()
}

fn main() {
    let nodes = vec!["A".to_string(), "B".to_string(), "C".to_string(), "D".to_string(), "E".to_string()];
    let mut graph = Graph::new(nodes);
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("C", "D", 3);
    graph.add_edge("D", "E", 4);
    graph.add_edge("E", "A", 5);
    let path = dijkstra(&graph, "A", "E");
    println!("{:?}", path);
}