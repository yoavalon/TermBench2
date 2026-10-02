use std::collections::{BinaryHeap, HashSet};
use std::cmp::Reverse;

fn dijkstra(graph: &std::collections::HashMap<&str, std::collections::HashMap<&str, i32>>, start: &str, end: &str) -> (Vec<&str>, i32) {
    let mut queue = BinaryHeap::new();
    queue.push((Reverse(0), start, vec![]));
    let mut visited = HashSet::new();
    while let Some((Reverse(cost), node, path)) = queue.pop() {
        if !visited.contains(node) {
            visited.insert(node);
            let mut new_path = path.clone();
            new_path.push(node);
            if node == end {
                return (new_path, cost);
            }
            if let Some(neighbors) = graph.get(node) {
                for (neighbor, &c) in neighbors {
                    if !visited.contains(neighbor) {
                        queue.push((Reverse(cost + c), neighbor, new_path.clone()));
                    }
                }
            }
        }
    }
    (vec![], 0)
}

fn main() {
    let graph: std::collections::HashMap<&str, std::collections::HashMap<&str, i32>> = [
        ("A", [("B", 1), ("C", 4)].iter().cloned().collect()),
        ("B", [("A", 1), ("C", 2), ("D", 5)].iter().cloned().collect()),
        ("C", [("A", 4), ("B", 2), ("D", 1)].iter().cloned().collect()),
        ("D", [("B", 5), ("C", 1)].iter().cloned().collect()),
    ].iter().cloned().collect();
    let start_node = "A";
    let end_node = "D";
    let (path, cost) = dijkstra(&graph, start_node, end_node);
    println!("Path: {:?}, Cost: {}", path, cost);
}