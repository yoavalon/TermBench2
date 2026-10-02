use std::collections::BinaryHeap;
use std::collections::HashMap;

fn dijkstra(graph: &HashMap<&str, HashMap<&str, f64>>, start: &str) -> HashMap<&str, f64> {
    let mut distances: HashMap<&str, f64> = graph.keys().map(|&node| (node, f64::INFINITY)).collect();
    distances.insert(start, 0.0);
    let mut priority_queue: BinaryHeap<(f64, &str)> = BinaryHeap::new();
    priority_queue.push((0.0, start));

    while let Some((current_distance, current_node)) = priority_queue.pop() {
        if current_distance != distances[current_node] {
            continue;
        }
        for (neighbor, &weight) in &graph[current_node] {
            let distance = current_distance + weight;
            if distance < distances[neighbor] {
                distances.insert(neighbor, distance);
                priority_queue.push((distance, neighbor));
            }
        }
    }

    distances
}

fn main() {
    let graph: HashMap<&str, HashMap<&str, f64>> = [
        ("A", [("B", 1.0), ("C", 4.0)].iter().cloned().collect()),
        ("B", [("A", 1.0), ("C", 2.0), ("D", 5.0)].iter().cloned().collect()),
        ("C", [("A", 4.0), ("B", 2.0), ("D", 1.0)].iter().cloned().collect()),
        ("D", [("B", 5.0), ("C", 1.0)].iter().cloned().collect()),
    ]
    .iter()
    .cloned()
    .collect();

    let start_node = "A";
    let result = dijkstra(&graph, start_node);
    for (node, &distance) in &result {
        println!("{}: {}", node, distance);
    }
}