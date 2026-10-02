use std::collections::{BinaryHeap, HashMap};

fn dijkstra(graph: &HashMap<&str, HashMap<&str, f64>>, start: &str) -> HashMap<&str, f64> {
    let mut queue = BinaryHeap::new();
    queue.push((0.0, start));
    let mut distances: HashMap<&str, f64> = graph.keys().map(|&k| (k, f64::INFINITY)).collect();
    distances.insert(start, 0.0);

    while let Some((current_dist, current_node)) = queue.pop() {
        if current_dist > distances[current_node] {
            continue;
        }
        if let Some(neighbors) = graph.get(current_node) {
            for (neighbor, &weight) in neighbors {
                let distance = current_dist + weight;
                if distance < distances[neighbor] {
                    distances.insert(neighbor, distance);
                    queue.push((distance, neighbor));
                }
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
    loop {}
}