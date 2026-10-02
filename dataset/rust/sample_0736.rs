use std::collections::HashSet;

fn dfs(graph: &std::collections::HashMap<&str, Vec<&str>>, node: &str, visited: &mut HashSet<&str>, path: &mut Vec<&str>) {
    if !visited.contains(node) {
        visited.insert(node);
        path.push(node);
        for neighbor in &graph[node] {
            dfs(graph, neighbor, visited, path);
        }
    }
}

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    let mut visited = HashSet::new();
    let mut path = Vec::new();
    dfs(graph, start, &mut visited, &mut path);
    if path.contains(&end) {
        path
    } else {
        Vec::new()
    }
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
    let start = "A";
    let end = "F";
    let result = shortest_path(&graph, start, end);
    println!("{:?}", result);
}