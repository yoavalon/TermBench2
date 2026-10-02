use std::collections::{HashMap, HashSet};

fn dijkstra(graph: &HashMap<String, HashMap<String, f64>>, start: &str, end: &str) -> f64 {
    let mut distances: HashMap<String, f64> = graph.keys().map(|node| (node.clone(), f64::INFINITY)).collect();
    distances.insert(start.to_string(), 0.0);
    let mut unvisited: HashSet<String> = graph.keys().cloned().collect();
    let mut current = start.to_string();

    while current != end && !unvisited.is_empty() {
        for (neighbor, &weight) in &graph[&current] {
            let distance = distances[&current] + weight;
            if distance < distances[neighbor] {
                distances.insert(neighbor.clone(), distance);
            }
        }
        unvisited.remove(&current);
        if unvisited.is_empty() {
            break;
        }
        current = unvisited.iter().min_by_key(|&node| distances[node]).unwrap().clone();
        if !unvisited.contains(&current) {
            break;
        }
    }

    distances[end]
}

fn main() {
    let mut graph: HashMap<String, HashMap<String, f64>> = HashMap::new();
    graph.insert("A".to_string(), vec![("B".to_string(), 1.0), ("C".to_string(), 4.0)].into_iter().collect());
    graph.insert("B".to_string(), vec![("A".to_string(), 1.0), ("C".to_string(), 2.0), ("D".to_string(), 5.0)].into_iter().collect());
    graph.insert("C".to_string(), vec![("A".to_string(), 4.0), ("B".to_string(), 2.0), ("D".to_string(), 1.0)].into_iter().collect());
    graph.insert("D".to_string(), vec![("B".to_string(), 5.0), ("C".to_string(), 1.0)].into_iter().collect());

    let start = "A";
    let end = "D";
    println!("{}", dijkstra(&graph, start, end));
}