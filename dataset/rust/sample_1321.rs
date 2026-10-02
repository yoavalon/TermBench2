use std::collections::{HashSet, VecDeque};

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    let mut queue: VecDeque<(&str, Vec<&str>)> = VecDeque::new();
    queue.push_back((start, vec![start]));
    let mut visited: HashSet<&str> = HashSet::new();
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

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    bfs(graph, start, end)
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
    let start = "A";
    let end = "F";
    println!("{:?}", shortest_path(&graph, start, end));
}