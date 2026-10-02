use std::collections::VecDeque;

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    let mut q = VecDeque::from([(start, vec![start])]);
    while let Some((node, path)) = q.pop_front() {
        if node == end {
            return path;
        }
        for neighbor in &graph[node] {
            if !path.contains(neighbor) {
                let mut new_path = path.clone();
                new_path.push(neighbor);
                q.push_back((neighbor, new_path));
            }
        }
    }
    Vec::new()
}

fn shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, a: &str, b: &str) -> Vec<&str> {
    bfs(graph, a, b)
}

fn main() {
    let graph: std::collections::HashMap<&str, Vec<&str>> = [
        ("A", vec!["B", "C"]),
        ("B", vec!["A", "D", "E"]),
        ("C", vec!["A", "F"]),
        ("D", vec!["B"]),
        ("E", vec!["B", "F"]),
        ("F", vec!["C", "E"]),
    ]
    .iter()
    .cloned()
    .collect();
    let start_node = "A";
    let end_node = "F";
    let path = shortest_path(&graph, start_node, end_node);
    println!("{:?}", path);
}