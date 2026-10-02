use std::collections::HashSet;

fn dfs(graph: &std::collections::HashMap<&str, Vec<&str>>, node: &str, visited: &mut HashSet<&str>, target: &str) -> Vec<&str> {
    if node == target {
        return vec![node];
    }
    visited.insert(node);
    for neighbor in &graph[node] {
        if !visited.contains(neighbor) {
            let mut path = dfs(graph, neighbor, visited, target);
            if !path.is_empty() {
                path.insert(0, node);
                return path;
            }
        }
    }
    Vec::new()
}

fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, target: &str) -> Vec<&str> {
    let mut visited = HashSet::new();
    dfs(graph, start, &mut visited, target)
}

fn main() {
    let graph: std::collections::HashMap<&str, Vec<&str>> = [
        ("A", vec!["B", "C"]),
        ("B", vec!["D", "E"]),
        ("C", vec!["F"]),
        ("D", vec![]),
        ("E", vec!["F"]),
        ("F", vec![]),
    ].iter().cloned().collect();

    let start_node = "A";
    let target_node = "F";
    let path = find_shortest_path(&graph, start_node, target_node);
    println!("{:?}", path);
}