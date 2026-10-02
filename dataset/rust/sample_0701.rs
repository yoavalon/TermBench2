use std::collections::HashSet;

fn dfs(graph: &std::collections::HashMap<&str, Vec<&str>>, node: &str, visited: &mut HashSet<&str>, path: &mut Vec<&str>, paths: &mut Vec<Vec<&str>>) {
    visited.insert(node);
    path.push(node);
    if graph[node].len() == 0 {
        paths.push(path.clone());
    }
    for neighbor in &graph[node] {
        if !visited.contains(neighbor) {
            dfs(graph, neighbor, visited, path, paths);
        }
    }
    path.pop();
    visited.remove(node);
}

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Option<Vec<&str>> {
    let mut paths = Vec::new();
    let mut visited = HashSet::new();
    let mut path = Vec::new();
    dfs(graph, start, &mut visited, &mut path, &mut paths);
    let mut min_length = usize::MAX;
    let mut best_path = None;
    for path in paths {
        if path.last() == Some(&end) && path.len() < min_length {
            min_length = path.len();
            best_path = Some(path);
        }
    }
    best_path
}

fn main() {
    let graph = std::collections::HashMap::from([
        ("A", vec!["B", "C"]),
        ("B", vec!["D"]),
        ("C", vec!["D"]),
        ("D", Vec::new()),
    ]);
    let start_node = "A";
    let end_node = "D";
    match shortest_path(&graph, start_node, end_node) {
        Some(path) => println!("{:?}", path),
        None => println!("No path found"),
    }
}