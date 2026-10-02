use std::collections::HashSet;

fn dfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str, visited: &mut HashSet<&str>) -> Option<Vec<&str>> {
    visited.insert(start);
    if start == end {
        return Some(vec![start]);
    }
    for neighbor in &graph[start] {
        if !visited.contains(neighbor) {
            if let Some(path) = dfs(graph, neighbor, end, visited) {
                return Some(vec![start].into_iter().chain(path.into_iter()).collect());
            }
        }
    }
    None
}

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> i32 {
    let mut visited = HashSet::new();
    if let Some(path) = dfs(graph, start, end, &mut visited) {
        return (path.len() - 1) as i32;
    }
    -1
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec!["B", "C"]);
    graph.insert("B", vec!["D", "E"]);
    graph.insert("C", vec!["F"]);
    graph.insert("D", vec!["G"]);
    graph.insert("E", vec!["G"]);
    graph.insert("F", vec!["G"]);
    graph.insert("G", vec![]);
    let start_node = "A";
    let end_node = "G";
    let result = shortest_path(&graph, start_node, end_node);
    println!("{}", result);
}