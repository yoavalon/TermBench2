use std::collections::HashMap;

struct Graph {
    nodes: HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: &str, v: &str, weight: i32) {
        self.nodes.entry(u.to_string()).or_insert_with(Vec::new).push((v.to_string(), weight));
        if !self.nodes.contains_key(v) {
            self.nodes.insert(v.to_string(), Vec::new());
        }
    }
}

fn dijkstra(graph: &Graph, start: &str) -> HashMap<String, i32> {
    let mut distances = graph.nodes.keys().map(|&node| (node.to_string(), i32::MAX)).collect::<HashMap<_, _>>();
    distances.insert(start.to_string(), 0);
    let mut unvisited = graph.nodes.keys().cloned().collect::<Vec<_>>();

    while !unvisited.is_empty() {
        let current = unvisited.iter().min_by_key(|&node| distances[&node]).unwrap().clone();
        unvisited.retain(|&node| node != current);
        for (neighbor, weight) in &graph.nodes[&current] {
            let distance = distances[&current] + weight;
            if distance < distances[neighbor] {
                distances.insert(neighbor.clone(), distance);
            }
        }
    }

    distances
}

fn find_shortest_path(graph: &Graph, start: &str, end: &str) -> Vec<String> {
    let distances = dijkstra(graph, start);
    let mut path = Vec::new();
    let mut current = end.to_string();

    while current != start {
        path.push(current.clone());
        for (neighbor, weight) in &graph.nodes[&current] {
            if distances[&current] == distances[neighbor] + weight {
                current = neighbor.clone();
                break;
            }
        }
    }
    path.push(start.to_string());
    path.reverse();
    path
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("C", "D", 3);
    graph.add_edge("D", "A", 4);
    let start_node = "A";
    let end_node = "D";
    let shortest_path = find_shortest_path(&graph, start_node, end_node);
    println!("Shortest path: {:?}", shortest_path);
}