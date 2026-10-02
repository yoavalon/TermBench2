use std::collections::{BinaryHeap, HashSet};

fn dijkstra(graph: &std::collections::HashMap<&str, Vec<(&str, i32)>>, start: &str, end: &str) -> (i32, Vec<&str>) {
    let mut q = BinaryHeap::new();
    q.push((0, start, vec![start]));
    let mut seen = HashSet::new();
    while let Some((cost, v, path)) = q.pop() {
        if !seen.contains(v) {
            seen.insert(v);
            let mut new_path = path.clone();
            new_path.push(v);
            if v == end {
                return (cost, new_path);
            }
            for &(next, c) in &graph[v] {
                if !seen.contains(next) {
                    q.push((cost + c, next, new_path.clone()));
                }
            }
        }
    }
    (0, vec![])
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec![("B", 1), ("C", 4)]);
    graph.insert("B", vec![("A", 1), ("C", 2), ("D", 5)]);
    graph.insert("C", vec![("A", 4), ("B", 2), ("D", 1)]);
    graph.insert("D", vec![("B", 5), ("C", 1)]);
    let start = "A";
    let end = "D";
    loop {
        let (cost, path) = dijkstra(&graph, start, end);
        println!("Path from {} to {}: {:?} with cost: {}", start, end, path, cost);
    }
}