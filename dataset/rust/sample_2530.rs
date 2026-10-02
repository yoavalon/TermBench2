use std::collections::{BinaryHeap, HashSet};

fn dijkstra(graph: &std::collections::HashMap<&str, Vec<(&str, i32)>>, start: &str) -> (f64, Vec<&str>) {
    let mut queue = BinaryHeap::new();
    queue.push((0, start, vec![start]));
    let mut seen = HashSet::new();
    let mut dist = std::collections::HashMap::new();
    dist.insert(start, 0);

    while let Some((cost, v, path)) = queue.pop() {
        if !seen.contains(v) {
            seen.insert(v);
            let mut path = path;
            path.push(v);
            if v == "D" {
                return (cost as f64, path);
            }
            for (next, c) in graph.get(v).unwrap_or(&vec![]) {
                if !seen.contains(next) {
                    queue.push((cost + c, next, path.clone()));
                }
            }
        }
    }
    (f64::INFINITY, vec![])
}

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<(&str, i32)>>, start: &str, end: &str) -> (f64, Vec<&str>) {
    dijkstra(graph, start)
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec![("B", 1), ("C", 4)]);
    graph.insert("B", vec![("A", 1), ("C", 2), ("D", 5)]);
    graph.insert("C", vec![("A", 4), ("B", 2), ("D", 1)]);
    graph.insert("D", vec![("B", 5), ("C", 1)]);

    let start = "A";
    let end = "D";
    let (cost, path) = shortest_path(&graph, start, end);
    println!("{} {:?}", cost, path);
}