use std::collections::HashSet;

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Option<Vec<&str>> {
    let mut queue: Vec<(String, Vec<String>)> = vec![(start.to_string(), vec![start.to_string()])];
    let mut visited: HashSet<String> = HashSet::new();

    while let Some((node, path)) = queue.pop(0) {
        if !visited.contains(&node) {
            visited.insert(node.clone());
            if node == end {
                return Some(path);
            }
            for neighbor in &graph[&node] {
                if !visited.contains(neighbor) {
                    let mut new_path = path.clone();
                    new_path.push(neighbor.to_string());
                    queue.push((neighbor.to_string(), new_path));
                }
            }
        }
    }
    None
}

fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> i32 {
    if let Some(path) = bfs(graph, start, end) {
        (path.len() - 1) as i32
    } else {
        -1
    }
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec!["B", "C"]);
    graph.insert("B", vec!["D", "E"]);
    graph.insert("C", vec!["F"]);
    graph.insert("D", vec![]);
    graph.insert("E", vec!["F"]);
    graph.insert("F", vec![]);

    let start = "A";
    let end = "F";
    let result = find_shortest_path(&graph, start, end);
    println!("{}", result);
}