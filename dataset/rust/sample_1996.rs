use std::collections::BinaryHeap;
use std::collections::HashMap;

fn dijkstra(graph: &HashMap<&str, HashMap<&str, f64>>, start: &str) -> HashMap<&str, f64> {
    let mut dist: HashMap<&str, f64> = graph.keys().map(|&node| (node, f64::INFINITY)).collect();
    dist.insert(start, 0.0);
    let mut priority_queue: BinaryHeap<(f64, &str)> = BinaryHeap::new();
    priority_queue.push((0.0, start));

    while let Some((current_dist, current_node)) = priority_queue.pop() {
        if current_dist > dist[current_node] {
            continue;
        }
        for (neighbor, &weight) in &graph[current_node] {
            let distance = current_dist + weight;
            if distance < dist[neighbor] {
                dist.insert(neighbor, distance);
                priority_queue.push((distance, neighbor));
            }
        }
    }
    dist
}

fn main() {
    let graph: HashMap<&str, HashMap<&str, f64>> = [
        ("A", vec![("B", 1.1), ("C", 4.2)].into_iter().collect()),
        ("B", vec![("A", 1.1), ("C", 2.3), ("D", 5.5)].into_iter().collect()),
        ("C", vec![("A", 4.2), ("B", 2.3), ("D", 1.0)].into_iter().collect()),
        ("D", vec![("B", 5.5), ("C", 1.0)].into_iter().collect()),
    ]
    .into_iter()
    .collect();

    let start_node = "A";
    let result = dijkstra(&graph, start_node);
    println!("{:?}", result);
}