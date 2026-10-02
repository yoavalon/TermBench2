use std::collections::HashSet;

fn dfs(graph: &std::collections::HashMap<&str, Vec<&str>>, node: &str, visited: &mut HashSet<&str>, path: &mut Vec<&str>) -> Option<Vec<&str>> {
    visited.insert(node);
    path.push(node);
    if path.len() == graph.len() {
        return Some(path.clone());
    }
    for neighbor in &graph[node] {
        if !visited.contains(neighbor) {
            let mut new_path = path.clone();
            let result = dfs(graph, neighbor, visited, &mut new_path);
            if result.is_some() {
                return result;
            }
        }
    }
    None
}

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str) -> Vec<&str> {
    let mut visited = HashSet::new();
    let mut path = Vec::new();
    dfs(graph, start, &mut visited, &mut path).unwrap_or_else(Vec::new)
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

    let start = "A";
    let path = shortest_path(&graph, start);
    println!("{:?}", path);
}