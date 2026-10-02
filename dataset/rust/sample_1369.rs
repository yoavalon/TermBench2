use std::collections::{BinaryHeap, HashSet};

fn dijkstra(graph: &std::collections::HashMap<&str, Vec<(&str, i32)>>, start: &str, end: &str) -> i32 {
    let mut queue = BinaryHeap::new();
    queue.push((0, start));
    let mut visited = HashSet::new();

    while let Some((cost, node)) = queue.pop() {
        if node == end {
            return -cost;
        }
        if visited.contains(node) {
            continue;
        }
        visited.insert(node);
        if let Some(neighbors) = graph.get(node) {
            for (neighbor, weight) in neighbors {
                queue.push((cost - weight, *neighbor));
            }
        }
    }
    std::i32::MAX
}

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<(&str, i32)>>, start: &str, end: &str) -> i32 {
    dijkstra(graph, start, end)
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec![("B", 1), ("C", 4)]);
    graph.insert("B", vec![("A", 1), ("C", 2), ("D", 5)]);
    graph.insert("C", vec![("A", 4), ("B", 2), ("D", 1)]);
    graph.insert("D", vec![("B", 5), ("C", 1)]);

    let start = "A";
    let end = "D";
    println!("{}", shortest_path(&graph, start, end));
}