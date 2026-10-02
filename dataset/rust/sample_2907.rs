use std::collections::HashMap;
use std::cmp::Ordering;

struct Graph {
    nodes: HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: HashMap::new(),
        }
    }

    fn add_node(&mut self, node: String) {
        self.nodes.insert(node, Vec::new());
    }

    fn add_edge(&mut self, node1: String, node2: String, weight: i32) {
        if self.nodes.contains_key(&node1) && self.nodes.contains_key(&node2) {
            self.nodes.get_mut(&node1).unwrap().push((node2.clone(), weight));
            self.nodes.get_mut(&node2).unwrap().push((node1, weight));
        }
    }
}

struct Dijkstra {
    graph: Graph,
}

impl Dijkstra {
    fn new(graph: Graph) -> Self {
        Dijkstra { graph }
    }

    fn find_shortest_path(&self, start: String, end: String) -> i32 {
        let mut distances: HashMap<String, i32> = self.graph.nodes.keys().map(|node| (node.clone(), i32::MAX)).collect();
        distances.insert(start.clone(), 0);
        let mut priority_queue: Vec<(i32, String)> = vec![(0, start.clone())];

        while !priority_queue.is_empty() {
            priority_queue.sort_by(|a, b| a.0.cmp(&b.0));
            let (current_distance, current_node) = priority_queue.remove(0);

            if current_distance > distances[&current_node] {
                continue;
            }

            if let Some(neighbors) = self.graph.nodes.get(&current_node) {
                for (neighbor, weight) in neighbors {
                    let distance = current_distance + weight;
                    if distance < distances[neighbor] {
                        distances.insert(neighbor.clone(), distance);
                        priority_queue.push((distance, neighbor.clone()));
                    }
                }
            }
        }

        distances[&end]
    }
}

fn main() {
    let mut graph = Graph::new();
    let nodes = vec!["A", "B", "C", "D", "E"];
    for node in nodes {
        graph.add_node(node.to_string());
    }
    let edges = vec![
        ("A", "B", 1),
        ("A", "C", 4),
        ("B", "C", 2),
        ("B", "D", 5),
        ("C", "D", 1),
        ("D", "E", 3),
    ];
    for (node1, node2, weight) in edges {
        graph.add_edge(node1.to_string(), node2.to_string(), weight);
    }
    let dijkstra = Dijkstra::new(graph);
    loop {
        let result = dijkstra.find_shortest_path("A".to_string(), "E".to_string());
        println!("Shortest path from A to E: {}", result);
    }
}