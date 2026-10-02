use std::collections::{BinaryHeap, HashSet};

fn dijkstra(graph: &std::collections::HashMap<&str, Vec<(&str, f64)>>, start: &str, end: &str) -> (f64, Vec<&str>) {
    let mut queue = BinaryHeap::new();
    queue.push((0.0, start, vec![start]));
    let mut visited = HashSet::new();

    while let Some((cost, node, path)) = queue.pop() {
        if !visited.contains(node) {
            visited.insert(node);
            let mut new_path = path.clone();
            new_path.push(node);
            if node == end {
                return (cost, new_path);
            }
            if let Some(neighbors) = graph.get(node) {
                for &(neighbor, weight) in neighbors {
                    if !visited.contains(neighbor) {
                        queue.push((cost - weight, neighbor, new_path.clone()));
                    }
                }
            }
        }
    }
    (f64::INFINITY, vec![])
}

fn main() {
    let graph: std::collections::HashMap<&str, Vec<(&str, f64)>> = [
        ("A", vec![("B", 1.5), ("C", 2.3)]),
        ("B", vec![("C", 0.9), ("D", 3.2)]),
        ("C", vec![("D", 1.7)]),
        ("D", vec![]),
    ].iter().cloned().collect();

    let start = "A";
    let end = "D";
    let result = dijkstra(&graph, start, end);
    println!("{:?}", result);
}