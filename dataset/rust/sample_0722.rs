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

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> i32 {
    let mut visited = HashSet::new();
    let mut path = Vec::new();
    dfs(graph, start, &mut visited, &mut path);
    if let Some(index) = path.iter().position(|&x| x == end) {
        return index as i32;
    }
    -1
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
    let end_node = "F";
    let result = shortest_path(&graph, start_node, end_node);
    println!("{}", result);
}