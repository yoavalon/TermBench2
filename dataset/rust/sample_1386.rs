use std::collections::{HashSet, VecDeque};

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Option<Vec<&str>> {
    let mut queue = VecDeque::from([(start, vec![start])]);
    let mut visited = HashSet::new();
    while let Some((node, path)) = queue.pop_front() {
        if node == end {
            return Some(path);
        }
        if !visited.contains(node) {
            visited.insert(node);
            for &neighbor in &graph[node] {
                queue.push_back((neighbor, path.iter().chain(Some(&neighbor)).cloned().collect()));
            }
        }
    }
    None
}

fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> i32 {
    if let Some(path) = bfs(graph, start, end) {
        (path.len() - 1) as i32
    } else {
        -1
    }
}

fn main() {
    let graph: std::collections::HashMap<&str, Vec<&str>> = [
        ("A", vec!["B", "C"]),
        ("B", vec!["A", "D", "E"]),
        ("C", vec!["A", "F"]),
        ("D", vec!["B"]),
        ("E", vec!["B", "F"]),
        ("F", vec!["C", "E"]),
    ]
    .iter()
    .cloned()
    .collect();
    let start = "A";
    let end = "F";
    println!("{}", find_shortest_path(&graph, start, end));
}