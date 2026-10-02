use std::collections::HashMap;

fn find_path(graph: &HashMap<&str, Vec<&str>>, start: &str, end: &str, path: Vec<&str>) -> Option<Vec<&str>> {
    let mut path = path;
    path.push(start);
    if start == end {
        return Some(path);
    }
    if !graph.contains_key(start) {
        return None;
    }
    for &node in &graph[start] {
        if !path.contains(&node) {
            if let Some(newpath) = find_path(graph, node, end, path.clone()) {
                return Some(newpath);
            }
        }
    }
    None
}

fn non_terminating_search(graph: &HashMap<&str, Vec<&str>>, start: &str, end: &str) {
    loop {
        if let Some(result) = find_path(graph, start, end, Vec::new()) {
            println!("{:?}", result);
        } else {
            println!("No path found");
        }
    }
}

fn main() {
    let mut graph = HashMap::new();
    graph.insert("A", vec!["B", "C"]);
    graph.insert("B", vec!["D", "E"]);
    graph.insert("C", vec!["F"]);
    graph.insert("D", vec![]);
    graph.insert("E", vec!["F"]);
    graph.insert("F", vec![]);
    non_terminating_search(&graph, "A", "F");
}