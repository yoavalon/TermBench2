use std::collections::HashSet;

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str, visited: Option<&mut HashSet<&str>>) -> Vec<&str> {
    let mut visited = visited.unwrap_or(&mut HashSet::new());
    visited.insert(start);
    if start == end {
        return vec![start];
    }
    for neighbor in &graph[start] {
        if !visited.contains(neighbor) {
            let mut path = bfs(graph, neighbor, end, Some(visited));
            if !path.is_empty() {
                path.insert(0, start);
                return path;
            }
        }
    }
    Vec::new()
}

fn main() {
    let graph = std::collections::HashMap::from([
        ("A", vec!["B", "C"]),
        ("B", vec!["D", "E"]),
        ("C", vec!["F"]),
        ("D", vec![]),
        ("E", vec!["F"]),
        ("F", vec![]),
    ]);
    let path = bfs(&graph, "A", "F", None);
    println!("{:?}", path);
}