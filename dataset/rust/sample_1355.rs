use std::collections::{HashSet, VecDeque};

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    let mut queue = VecDeque::from([(start, vec![start])]);
    let mut visited = HashSet::new();
    while let Some((node, path)) = queue.pop_front() {
        if node == end {
            return path;
        }
        if !visited.contains(node) {
            visited.insert(node);
            for neighbor in &graph[node] {
                let mut new_path = path.clone();
                new_path.push(neighbor);
                queue.push_back((neighbor, new_path));
            }
        }
    }
    Vec::new()
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
    let path = bfs(&graph, "A", "F");
    println!("{:?}", path);
}