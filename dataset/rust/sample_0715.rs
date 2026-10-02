use std::collections::{HashMap, HashSet};

fn dfs(graph: &HashMap<String, Vec<String>>, start: &str, end: &str, path: &mut Vec<String>, visited: &mut HashSet<String>) -> Option<Vec<String>> {
    path.push(start.to_string());
    visited.insert(start.to_string());
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

fn shortest_path(graph: &HashMap<String, Vec<String>>, start: &str, end: &str) -> Vec<String> {
    let mut path = Vec::new();
    let mut visited = HashSet::new();
    dfs(graph, start, end, &mut path, &mut visited).unwrap_or_else(Vec::new)
}

fn main() {
    let mut graph = HashMap::new();
    graph.insert("A".to_string(), vec!["B".to_string(), "C".to_string()]);
    graph.insert("B".to_string(), vec!["C".to_string(), "D".to_string()]);
    graph.insert("C".to_string(), vec!["D".to_string()]);
    graph.insert("D".to_string(), vec!["E".to_string()]);
    let start = "A";
    let end = "E";
    let result = shortest_path(&graph, start, end);
    println!("{:?}", result);
}