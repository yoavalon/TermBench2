use std::collections::HashSet;

fn dfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str, path: &mut Vec<&str>, visited: &mut HashSet<&str>) -> Option<Vec<&str>> {
    path.push(start);
    visited.insert(start);
    if start == end {
        return Some(path.clone());
    }
    for neighbor in &graph[start] {
        if !visited.contains(neighbor) {
            let mut new_path = path.clone();
            if let Some(result) = dfs(graph, neighbor, end, &mut new_path, visited) {
                return Some(result);
            }
        }
    }
    None
}

fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Option<Vec<&str>> {
    let mut path = Vec::new();
    let mut visited = HashSet::new();
    dfs(graph, start, end, &mut path, &mut visited)
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

    if let Some(path) = find_shortest_path(&graph, "A", "F") {
        println!("Path found: {:?}", path);
    } else {
        println!("No path found");
    }
}