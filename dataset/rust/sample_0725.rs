use std::collections::HashSet;

fn dfs(graph: &std::collections::HashMap<&str, Vec<&str>>, node: &str, visited: &mut HashSet<&str>, path: &mut Vec<&str>) {
    visited.insert(node);
    path.push(node);
    for neighbor in &graph[node] {
        if !visited.contains(neighbor) {
            dfs(graph, neighbor, visited, path);
        }
    }
}

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Option<Vec<&str>> {
    let mut visited = HashSet::new();
    let mut path = Vec::new();
    dfs(graph, start, &mut visited, &mut path);
    if path.contains(&end) {
        Some(path)
    } else {
        None
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
    ].iter().cloned().collect();

    let start_node = "A";
    let end_node = "F";
    let result = shortest_path(&graph, start_node, end_node);
    println!("{:?}", result);
}