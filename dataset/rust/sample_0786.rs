fn find_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str, path: Option<Vec<&str>>) -> Option<Vec<&str>> {
    let mut path = path.unwrap_or_else(Vec::new);
    path.push(start);
    if start == end {
        return Some(path);
    }
    if !graph.contains_key(start) {
        return None;
    }
    for &node in &graph[start] {
        if !path.contains(&node) {
            if let Some(newpath) = find_path(graph, node, end, Some(path.clone())) {
                return Some(newpath);
            }
        }
    }
    None
}

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> usize {
    if let Some(path) = find_path(graph, start, end, None) {
        path.len() - 1
    } else {
        std::usize::MAX
    }
}

fn main() {
    let g = std::collections::HashMap::from([
        ("A", vec!["B", "C"]),
        ("B", vec!["D", "E"]),
        ("C", vec!["F"]),
        ("D", vec![]),
        ("E", vec!["F"]),
        ("F", vec![]),
    ]);
    println!("{}", shortest_path(&g, "A", "F"));
}