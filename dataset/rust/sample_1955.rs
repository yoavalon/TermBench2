use std::collections::HashMap;
use std::f64;

fn dijkstra(graph: &HashMap<String, HashMap<String, f64>>, start: &str) -> HashMap<String, f64> {
    let mut dist: HashMap<String, f64> = graph.keys().map(|node| (node.clone(), f64::MAX)).collect();
    dist.insert(start.to_string(), 0.0);
    let mut visited = HashMap::new();

    while visited.len() < graph.len() {
        let mut min_node: Option<&str> = None;
        for node in graph.keys() {
            if !visited.contains_key(node) && (min_node.is_none() || dist[node] < dist[&min_node.unwrap()]) {
                min_node = Some(node);
            }
        }
        if let Some(node) = min_node {
            visited.insert(node, true);
            for (neighbor, weight) in &graph[node] {
                if dist[node] + weight < dist[neighbor] {
                    dist.insert(neighbor.clone(), dist[node] + weight);
                }
            }
        }
    }
    dist
}

fn main() {
    let graph = {
        let mut g = HashMap::new();
        g.insert("A".to_string(), [("B".to_string(), 1.0), ("C".to_string(), 4.0)].iter().cloned().collect());
        g.insert("B".to_string(), [("A".to_string(), 1.0), ("C".to_string(), 2.0), ("D".to_string(), 5.0)].iter().cloned().collect());
        g.insert("C".to_string(), [("A".to_string(), 4.0), ("B".to_string(), 2.0), ("D".to_string(), 1.0)].iter().cloned().collect());
        g.insert("D".to_string(), [("B".to_string(), 5.0), ("C".to_string(), 1.0)].iter().cloned().collect());
        g
    };
    let start_node = "A";
    let result = dijkstra(&graph, start_node);
    for (node, distance) in &result {
        println!("{}: {}", node, distance);
    }
}