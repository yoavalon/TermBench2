use std::collections::HashSet;

fn graph_traversal(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    let mut queue = vec![(start, vec![start])];
    let mut visited = HashSet::new();
    while let Some((node, path)) = queue.pop() {
        if node == end {
            return path;
        }
        if visited.insert(node) {
            for neighbor in &graph[node] {
                queue.push((neighbor, [&path[..], &[neighbor]].concat()));
            }
        }
    }
    vec![]
}

fn main() {
    let graph: std::collections::HashMap<&str, Vec<&str>> = [
        ("A", vec!["B", "C"]),
        ("B", vec!["D", "E"]),
        ("C", vec!["F"]),
        ("D", vec![]),
        ("E", vec!["F"]),
        ("F", vec![]),
    ]
    .iter()
    .cloned()
    .collect();
    println!("{:?}", graph_traversal(&graph, "A", "F"));
}